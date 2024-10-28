// Knuth–Morris–Pratt algorithm
vector<long long> prefixFunction(vector<long long> &v, long long n){
    vector<long long> pi(n);
    pi[0] = 0;
    for(long long i = 1; i < n; ++i){
        long long j = pi[i-1];
        while(j > 0 && v[i] != v[j]){
            j = pi[j-1];
        }
        if(v[i] == v[j]){
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

// Knuth–Morris–Pratt algorithm
vector<long long> prefixFunction(string &s, long long n){
    vector<long long> pi(n);
    pi[0] = 0;
    for(long long i = 1; i < n; ++i){
        long long j = pi[i-1];
        while(j > 0 && s[i] != s[j]){
            j = pi[j-1];
        }
        if(s[i] == s[j]){
            j++;
        }
        pi[i] = j;
    }
    return pi;
}