// LCA using in out time
const long long nodesCnt = 2e5 + 5;
long long par[nodesCnt][20]; // 20 for 2 * 1e5, 25 for 1e7, and so on..
long long in[nodesCnt], out[nodesCnt];
long long timer;

// Initialization 
// timer = 0;
// preDfs(1, 1, adj)

// 1 - based indexing for nodes
void preDfs(long long u, long long p, vector<vector<long long>> &adj){
    in[u] = ++timer;
    par[u][0] = p;
    
    for(long long i = 1; i < 20; ++i){
        par[u][i] = par[par[u][i-1]][i-1];
    }
    
    for(auto &v : adj[u]){
        if(v == p) continue;
        preDfs(v, u, adj);
    }

    out[u] = ++timer;
}
 
bool is_ancestor(long long u, long long v){
    return (in[u] <= in[v] && out[u] >= out[v]);
}
 
long long lca(long long u, long long v){
    if(is_ancestor(u, v)) return u;
    if(is_ancestor(v, u)) return v;
    
    for(long long i = 19; i >= 0; --i){
        if(!is_ancestor(par[u][i], v)){
            u = par[u][i];
        }
    }
    
    return par[u][0];
}