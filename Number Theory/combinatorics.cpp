// Factorial & inverse Factorial Calculation
const long long factSize = 2e6 + 5;
long long fact[factSize];
long long invFact[factSize];

void preComputeFact(){
    fact[0] = 1;
    for(long long i = 1; i < factSize; ++i){
        fact[i] = (fact[i - 1] * i) % mod;
    }
    invFact[factSize - 1] = binPower(fact[factSize - 1], mod - 2, mod);
    for(long long i = factSize - 2; i >= 0; --i){
        invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
    }
}

// nCr Calculation
long long nCr(long long n, long long r){
    if(r < 0 || r > n) return 0ll;
    return ((fact[n] * invFact[n - r]) % mod * invFact[r]) % mod; 
}