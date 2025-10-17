/* 
    SOS DP

    Problem Statement: 
    Given an array f[] of size 2^n, we want to compute an array g[] of the same size such that for every mask,
    g[mask] = sum of f[submask] for all submasks of mask (submask & mask = submask).

    Explanation:
    Think as trie
    For each level from bottom to top
        For each mask
            If the ith bit is set in mask
                Add f[mask^(1<<i)] to f[mask] // add 0th bit contribution to 1st bit contribution
    Finally f will contain the required values

*/

const long long N = 20;
long long dp[1ll << N];

// calculate dp (to find contribution of subset, 1 <- 0)
void forward1(long long dp[]){
    for(long long i = 0; i < N; ++i){
        for(long long mask = 0; mask < (1ll << N); ++mask){
            if(mask & (1ll << i)){
                dp[mask] += dp[mask ^ (1ll << i)];
            }
        }
    }
}

// reverse above
void backward1(long long dp[]){
    for(long long i = N - 1; i >= 0; --i){
        for(long long mask = (1ll << N) - 1; mask >= 0; --mask){
            if(mask & (1ll << i)){
                dp[mask] -= dp[mask ^ (1ll << i)];
            }
        }
    }
}

// calculate dp (to find contribution of superset, 0 <- 1)
void forward2(long long dp[]){
    for(long long i = 0; i < N; ++i){
        for(long long mask = 0; mask < (1ll << N); ++mask){
            if(mask & (1ll << i)){
                dp[mask ^ (1ll << i)] += dp[mask];
            }
        }
    }
}

// reverse above
void backward2(long long dp[]){
    for(long long i = N - 1; i >= 0; --i){
        for(long long mask = (1ll << N) - 1; mask >= 0; --mask){
            if(mask & (1ll << i)){
                dp[mask ^ (1ll << i)] -= dp[mask];
            }
        }
    }
}