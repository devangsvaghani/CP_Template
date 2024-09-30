class DSU
{
public:
    ll n;
    vector<ll> size, par;
 
    DSU(ll n)
    {
        this->n = n;
        size.resize(n, 1);
        par.resize(n, 0);
 
        iota(all(par), 0);
    }
 
    ll find(ll u)
    {
        if (u == par[u])
            return u;
        return par[u] = find(par[u]);
    }
 
    void merge(ll u, ll v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return;
        if (size[u] < size[v])
            swap(u, v);
        size[u] += size[v];
        par[v] = u;
    }
 
    ll count_components()
    {
        ll cnt = 0;
        for (ll i = 1; i < n; ++i)
        {
            if (par[i] == i)
                ++cnt;
        }
 
        return cnt;
    }
};