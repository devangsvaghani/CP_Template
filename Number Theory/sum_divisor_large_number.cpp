vector<bool> isPrime(N, true);
vector<int> primes;

ll power(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void init(){
    isPrime[0] = isPrime[1] = 0;

    for(ll i = 2; i < N; ++i){
        if(isPrime[i]){
            primes.push_back(i);
            for(ll j = i * i; j < N; j += i){
                isPrime[j] = false;
            }
        }
    }
}

ll calc_geo_sum(ll a, ll b){
    // 1 + a + a^2 + ... + a^b

    // (a ^ (b + 1) - 1) / (a - 1)

    if(b == 0) return 1ll;

    if(b & 1){
        return power(a, b) + calc_geo_sum(a, b - 1);
    }

    ll half = b / 2;
    ll half_val = calc_geo_sum(a, half);
    return half_val + (half_val - 1) * power(a, half);
}

void solve(){
    ll x;
    cin >> x;

    ll temp = x, res = 1;

    for(auto &p : primes){
        if(p * 1ll * p > x) break;

        int c = 0;
        while(x % p == 0){
            x /= p;
            ++c;
        }

        if(c){
            res *= calc_geo_sum(p, c);
        }
    }

    if(x > 1){
        res *= (1 + x);
    }

    cout << (res - temp) << "\n";
}