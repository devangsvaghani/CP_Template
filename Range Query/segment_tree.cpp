


struct segNode{
  ll sum;
  segNode(){ // Indetity Element
    sum = 0;
  }

  segNode(ll ai){
    sum = ai;
  }

  // merge logic
  void merge(segNode& a, segNode& b){ 
    sum = a.sum + b.sum;
  }

  // update node
  void update(ll val){
    sum = val;
  }
};


class segTree{

  vector<segNode> tree;
  public:
  segTree(ll n){
    ll s = 1;
    while(s < 2 * n) s <<= 1;
    tree.resize(s);
    fill(tree.begin(), tree.end(), segNode());
  }

  void build(ll index, ll start, ll end, vector<ll> &arr){
    if(start == end){
      tree[index] = segNode(arr[start]);
      return;
    }

    ll mid = start + (end - start) / 2;
    build(2 * index + 1, start, mid, arr);
    build(2 * index + 2, mid + 1, end, arr);

    tree[index].merge(tree[2 * index + 1], tree[2 * index + 2]);
  }

  void build(vector<ll>& arr, ll n){
    build(0, 0, n-1, arr);
  }

  segNode query(ll index, ll start, ll end, ll left, ll right){
    if(start > right || end < left) return segNode();
    if(start >= left && end <= right) return tree[index];

    ll mid = start + (end - start) / 2;
    segNode l = query(2 * index + 1, start, mid, left, right);
    segNode r = query(2 * index + 2, mid + 1, end, left, right);
    segNode ans;
    ans.merge(l, r);
    return ans;
  }

  segNode query(ll left, ll right, ll n){
    return query(0, 0, n-1, left, right);
  }

  void update(ll index, ll start, ll end, ll pos, ll val){
    if(start == end){
      tree[index].update(val);
      return;
    }

    ll mid = start + (end - start) / 2;
    if(pos <= mid){
      update(2 * index + 1, start, mid, pos, val);
    }else{
      update(2 * index + 2, mid + 1, end, pos, val);
    }

    tree[index].merge(tree[2 * index + 1], tree[2 * index + 2]);
  }

  void update(ll pos, ll val, ll n){ // change according to update requirnment
    update(0, 0, n-1, pos, val);
  }
};