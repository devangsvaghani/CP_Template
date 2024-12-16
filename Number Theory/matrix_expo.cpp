// Matrix Exponentiation
vector<vector<long long>> matPower(vector<vector<long long>> a, long long b, long long mod){
    long long n = a.size();
    vector<vector<long long>> res(n, vector<long long>(n, 0));
    for(long long i = 0; i < n; ++i) res[i][i] = 1;

    while(b > 0){
        if(b & 1){
            vector<vector<long long>> res2(n, vector<long long>(n, 0));
            for(long long i = 0; i < n; ++i){
                for(long long j = 0; j < n; ++j){
                    for(long long k = 0; k < n; ++k){
                        res2[i][j] = (res2[i][j] + (res[i][k] * a[k][j]) % mod) % mod;
                    }
                }
            }
            res = res2;
        }

        vector<vector<long long>> a2(n, vector<long long>(n, 0));
        for(long long i = 0; i < n; ++i){
            for(long long j = 0; j < n; ++j){
                for(long long k = 0; k < n; ++k){
                    a2[i][j] = (a2[i][j] + (a[i][k] * a[k][j]) % mod) % mod;
                }
            }
        }
        a = a2;
        b >>= 1;
    }
    return res;
}

// Matrix Multiplication
vector<vector<long long>> matMultiply(vector<vector<long long>> &a, vector<vector<long long>> &b, long long mod){
    assert(a[0].size() == b.size());
    long long n = a.size(), m = a[0].size(), k = b[0].size();
    vector<vector<long long>> res(n, vector<long long>(k, 0));
    for(long long i = 0; i < n; ++i){
        for(long long j = 0; j < k; ++j){
            for(long long l = 0; l < m; ++l){
                res[i][j] = (res[i][j] + (a[i][l] * b[l][j]) % mod) % mod;
            }
        }
    }
    return res;
}