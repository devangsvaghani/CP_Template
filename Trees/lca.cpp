
// Code for binary lifting setup
void computeParent(ll n){
  for(ll i = 1; i < LG; ++i){
    for(ll node = 1; node <= n; ++node){
      parent[node][i] = parent[parent[node][i-1]][i-1];
    }
  }
}

// find LCA
ll lca(ll u, ll v){
  if(depth[v] < depth[u]){
    swap(u, v);
  }

  // to find kth ancestor using binary lifting
  ll diff = depth[v] - depth[u];
  for(ll i = 0; i < LG; ++i){
    if(((diff >> i) & 1)){
      v = parent[v][i];
    }
  }

  if(u == v){
    return u;
  }

  for(ll i = LG-1; i >= 0; --i){
    if(parent[u][i] != parent[v][i]){
      v = parent[v][i];
      u = parent[u][i];
    }
  }

  return parent[u][0];
}