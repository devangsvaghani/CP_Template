vector<long long> z_function(string &s, long long n){
    vector<long long> z(n);
    z[0] = 0;
    long long l = 0, r = 0;
    for(long long i = 1; i < n; ++i){
        if(i < r){
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]){
            z[i]++;
        }
        if(i + z[i] > r){
            l = i;
            r = i + z[i];
        }
    }
    return z;
}