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

// Binary Exponentiation without modulo
long long binPower(long long a, long long b){
    long long res = 1;
    while(b > 0){
        if(b & 1) res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}