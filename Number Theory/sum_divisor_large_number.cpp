// Binary Exponentiation with modulo
long long binPowerMod(long long a, long long b, long long m){
    long long res = 1;
    a %= m;
    while(b > 0){
        if(b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

// Sieve for prime numbers
const long long sieveSize = 1e7+1;
bool prime[sieveSize];
vector<long long> primes;

void preComputeSieve(){
    for(long long i = 2; i < sieveSize; ++i) prime[i] = true;
    for(long long i = 2; i < sieveSize; ++i){
        if(prime[i]){
                primes.push_back(i);
            for(long long j = i * i; j < sieveSize; j += i){
                prime[j] = false;
            }
        }
    }
}

long long findGeometricSum(long long a, long long b){
    // 1 + a + a^2 + ... + a^b = (a ^ (b + 1) - 1) / (a - 1)

    if(b == 0) return 1ll;

    if(b & 1){
        return binPowerMod(a, b, mod) + findGeometricSum(a, b - 1);
    }

    long long half = b / 2;
    long long half_val = findGeometricSum(a, half);
    return half_val + (half_val - 1) * binPowerMod(a, half, mod);
}

long long findDivisorsSum(long long x){
    long long temp = x, res = 1;

    for(auto &p : primes){
        if(p * p > x) break;

        int c = 0;
        while(x % p == 0){
            x /= p;
            ++c;
        }

        if(c){
            res *= findGeometricSum(p, c);
        }
    }

    if(x > 1){
        res *= (1 + x);
    }

   return (res - temp);
}