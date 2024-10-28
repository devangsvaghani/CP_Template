class DSU{
public:
    long long n;
    vector<long long> size, par;
 
    DSU(long long n){
        this -> n = n;
        size.resize(n);
        par.resize(n);
 
        for(long long i = 0; i < n; ++i){
            par[i] = i;
            size[i] = 1;
        }
    }
 
    long long find(long long u){
        if (u == par[u])
            return u;
        return par[u] = find(par[u]);
    }
 
    void merge(long long u, long long v){
        u = find(u); v = find(v);
        if (u == v) return;

        if (size[u] < size[v]){
            swap(u, v);
        } 
        size[u] += size[v];
        par[v] = u;
    }
 
    long long count_components(){
        long long cnt = 0;
        for (long long i = 1; i < n; ++i){
            if (par[i] == i) ++cnt;
        }
 
        return cnt;
    }
};