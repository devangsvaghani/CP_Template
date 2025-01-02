struct segNode{
    long long sum;
    
    segNode(){
        sum = 0;
    }
    
    void merge(segNode &x, segNode& y){
        sum = x.sum + y.sum;
    }
    
    void update(long long val){
        sum = val;
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
    
        build(1, 0, n-1, v);
    }
    
    void build(long long node, long long l, long long r, vector<long long> &v){
        if(l == r){
            tree[node].update(v[l]);
            return;
        }
    
        long long mid = l + (r - l)/2;
        build(node << 1, l, mid, v);
        build(node << 1 | 1, mid + 1, r, v);
    
        tree[node].merge(tree[node << 1], tree[node << 1 | 1]);
    }
    
    void update(long long pos, long long val){
        update(1, 0, n-1, pos, val);
    }
    
    void update(long long node, long long l, long long r, long long pos, long long val){
        if(l == r){
            tree[node].update(val);
            return;
        }
    
        long long mid = l + (r - l)/2;
        if(pos <= mid){
            update(node << 1, l, mid, pos, val);
        }else{
            update(node << 1 | 1, mid + 1, r, pos, val);
        }
    
        tree[node].merge(tree[node << 1], tree[node << 1 | 1]);
    }
    
    long long query(long long s, long long e){
        segNode ans = query(1, 0, n-1, s, e);
        
        return ans.sum;
    }
    
    segNode query(long long node, long long l, long long r, long long s, long long e){
        if(l >= s && r <= e) return tree[node];
    
        if(l > e || r < s) return segNode();
    
        long long mid = l + (r - l)/2;
    
        segNode ans, left, right;
        left = query(node << 1, l, mid, s, e);
        right = query(node << 1 | 1, mid + 1, r, s, e);
        ans.merge(left, right);
        
        return ans;
    }
};