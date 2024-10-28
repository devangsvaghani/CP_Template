struct segNode{
    long long sum, set;
    
    segNode(){
        sum = 0;
        set = -1;
    }
    
    segNode(long long x){
        sum = x;
        set = -1;
    }
    
    void merge(segNode &a, segNode &b){
        sum = a.sum + b.sum;
    }
    
    void lazy_add(ll x){
        set = x;
    }
    
    void lazy_apply(ll l, ll r){
        if(set != -1){
            sum = (r - l + 1) * set;
        }
    }
    
    void lazy_merge(segNode &par){
        if(par.set != -1) set = par.set;
    }
    
    void lazy_remove(){
        set = -1;
    }
}; 
 
class segTree{
    public:
    vector<segNode> tree;
    long long n;
    
    segTree(long long n){
        this -> n = n;
        tree.resize(4 * n, segNode());
    
        build(0, 0, n-1);
    }
    
    void build(long long node, long long l, long long r){
        if(l == r){
            tree[node] = segNode(0);
            return;
        }
    
        long long mid = l + (r - l)/2;
        build(2 * node + 1, l, mid);
        build(2 * node + 2, mid + 1, r);
    
        tree[node].merge(tree[2 * node + 1], tree[2 * node + 2]);
    }
    
    void push(long long node, long long l, long long r){
        tree[node].lazy_apply(l, r);
    
        if(l != r){
            tree[2 * node + 1].lazy_merge(tree[node]);
            tree[2 * node + 2].lazy_merge(tree[node]);
        }
    
        tree[node].lazy_remove();
    }
    
    void update(long long s, long long e, long long x){
        update(0, 0, n-1, s, e, x);
    }
    
    void update(long long node, long long l, long long r, long long s, long long e, long long x){
        push(node, l, r);
    
        if(l > e || r < s) return;
        if(l >= s && r <= e){
            tree[node].lazy_add(x);
            push(node, l, r);
            return;
        }
    
        long long mid = l + (r - l)/2;
        update(2 * node + 1, l, mid, s, e, x);
        update(2 * node + 2, mid + 1, r, s, e, x);
    
        tree[node].merge(tree[2 * node + 1], tree[2 * node + 2]);
    }
    
    long long query(long long s, long long e){
        return query(0, 0, n-1, s, e).sum;
    }
    
    segNode query(long long node, long long l, long long r, long long s, long long e){
        push(node, l, r);
    
        if(l > e || r < s) return segNode();
        if(l >= s && r <= e) return tree[node];
    
        long long mid = l + (r - l)/2;
        segNode ans, left, right;
        left = query(2 * node + 1, l, mid, s, e);
        right = query(2 * node + 2, mid + 1, r, s, e);
    
        ans.merge(left, right);
        return ans;
    }
};