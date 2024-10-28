struct segNode{
    long long mx;
    
    segNode(){
        mx = LLONG_MIN;
    }
    
    void merge(segNode &x, segNode& y){
        mx = max(x.mx, y.mx);
    }
    
    void update(long long val){
        mx = val;
    } 
};
 
class segTree{
    long long n;
    vector<segNode> tree;
    
    public:
    segTree(){}

    segTree(long long n){
        this -> n = n;
        tree.resize(4 * n);
    }

    segTree(vector<long long> &v, long long n){
        this -> n = n;
        tree.resize(4 * n);
        fill(all(tree), segNode());
    
        build(0, 0, n-1, v);
    }
    
    void build(long long node, long long l, long long r, vector<long long> &v){
        if(l == r){
            tree[node].update(v[l]);
            return;
        }
    
        long long mid = l + (r - l)/2;
        build(2 * node + 1, l, mid, v);
        build(2 * node + 2, mid + 1, r, v);
    
        tree[node].merge(tree[2 * node + 1], tree[2 * node + 2]);
    }
    
    void update(long long pos, long long val){
        update(0, 0, n-1, pos, val);
    }
    
    void update(long long node, long long l, long long r, long long pos, long long val){
        if(l == r){
            tree[node].update(val);
            return;
        }
    
        long long mid = l + (r - l)/2;
        if(pos <= mid){
            update(2 * node + 1, l, mid, pos, val);
        }else{
            update(2 * node + 2, mid + 1, r, pos, val);
        }
    
        tree[node].merge(tree[2 * node + 1], tree[2 * node + 2]);
    }
    
    long long query(long long s, long long e){
        segNode ans = query(0, 0, n-1, s, e);
        
        return ans.mx;
    }
    
    segNode query(long long node, long long l, long long r, long long s, long long e){
        if(l >= s && r <= e) return tree[node];
    
        if(l > e || r < s) return segNode();
    
        long long mid = l + (r - l)/2;
    
        segNode ans, left, right;
        left = query(2 * node + 1, l, mid, s, e);
        right = query(2 * node + 2, mid + 1, r, s, e);
        ans.merge(left, right);
        
        return ans;
    }
};