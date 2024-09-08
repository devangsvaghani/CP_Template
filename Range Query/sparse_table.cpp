// // C++20
// #include <bit>
// int log2_floor(unsigned long i) {
//     return std::bit_width(i) - 1;
// }

// // pre C++20
// int log2_floor(unsigned long long i) {
//     return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
// }

class SparseTable{
    vector<vector<ll>> st;
    vector<ll> lg;
    ll K;
    public:

    SparseTable(vector<ll> &v, ll &n){
        K = 20; // 20 for 2 * 1e5, 25 for 1e7, and so on..
        st.resize(K + 1, vector<ll> (n));
        lg.resize(n + 1);
        preComputeLG(n);
        preCompute(v, n);
    }

    void preComputeLG(ll &n){
        lg[0] = 1;
        for (ll i = 2; i <= n; i++){
            lg[i] = lg[i/2] + 1;
        }
    }

    void preCompute(vector<ll> &v, ll &n){
        // st[i][j] -> range [j, j + (1ll << i) - 1]
        // st[i][j] = st[i-1][j] + st[i-1][j + (1ll << (i-1))];

        copy(v.begin(), v.end(), st[0].begin());

        for(ll i = 1; i <= K; ++i){
            for(ll j = 0; j + (1ll << i) <= n; ++j){
                st[i][j] = min(st[i-1][j], st[i-1][j + (1ll << (i - 1))]);
            }
        }
    }

    ll query(ll l, ll r){
        // sum query
        // ll sum = 0;
        // for (ll i = K; i >= 0; i--) {
        //     if ((1 << i) <= R - L + 1) {
        //         sum += st[i][L];
        //         L += 1 << i;
        //     }
        // }

        // for idempotent functions like min, max, gcd, bitwise and, bitwise or, etc...
        ll i = lg[r - l + 1];
        ll mn = min(st[i][l], st[i][r - (1 << i) + 1]);
        return mn;
    }
};