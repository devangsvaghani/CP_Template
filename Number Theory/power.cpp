ll power(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b & 1) res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}



ll modPower(ll a, ll b, ll m){
    ll res = 1;
    while(b > 0){
        if(b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}