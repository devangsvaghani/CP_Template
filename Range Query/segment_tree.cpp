struct segNode{
  ll sum;
 
  segNode(){
    sum = 0;
  }
 
  void merge(segNode &x, segNode& y){
    sum = x.sum | y.sum;
  }
 
  void update(ll val){
    sum = val;
  } 
};
 
class segTree{
  ll n;
  vector<segNode> tree;
 
  public:
  segTree(vector<ll> &v, ll n){
    this -> n = n;
    tree.resize(4 * n);
    fill(all(tree), segNode());
 
    build(0, 0, n-1, v);
  }
 
  void build(ll node, ll l, ll r, vector<ll> &v){
    if(l == r){
      tree[node].update(v[l]);
      return;
    }
 
    ll mid = l + (r - l)/2;
    build(2 * node + 1, l, mid, v);
    build(2 * node + 2, mid + 1, r, v);
 
    tree[node].merge(tree[2 * node + 1], tree[2 * node + 2]);
  }
 
  void update(ll pos, ll val){
    update(0, 0, n-1, pos, val);
  }
 
  void update(ll node, ll l, ll r, ll pos, ll val){
    if(l == r){
      tree[node].update(val);
      return;
    }
 
    ll mid = l + (r - l)/2;
    if(pos <= mid){
      update(2 * node + 1, l, mid, pos, val);
    }else{
      update(2 * node + 2, mid + 1, r, pos, val);
    }
 
    tree[node].merge(tree[2 * node + 1], tree[2 * node + 2]);
  }
 
  ll query(ll s, ll e){
    segNode ans = query(0, 0, n-1, s, e);
    
    return ans.sum;
  }
 
  segNode query(ll node, ll l, ll r, ll s, ll e){
    if(l >= s && r <= e) return tree[node];
 
    if(l > e || r < s) return segNode();
 
    ll mid = l + (r - l)/2;
 
    segNode ans, left, right;
    left = query(2 * node + 1, l, mid, s, e);
    right = query(2 * node + 2, mid + 1, r, s, e);
    ans.merge(left, right);
    
    return ans;
  }
};