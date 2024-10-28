
// Single hash
class HashString{
    long long p = 31, m = 1e9+9;
    vector<long long> h, ppow;
    public:
 
    HashString(string &s){
        int n = s.length();
        h.resize(n + 1, 0);
        ppow.resize(n + 1, 0);
        ppow[0] = 1;
 
        for(int i = 1; i <= n; ++i){
            ppow[i] = (ppow[i - 1] * p) % m;
            h[i] = ((h[i - 1] * p) % m + (s[i - 1] - 'a' + 1)) % m;
        }
    }   
    
    // assume zero based indexing
    long long getSubHash(int l, int r){ 
        long long ans = (h[r + 1] - (h[l] * ppow[r - l + 1]) % m + m) % m;
        return ans;
    }
 
    long long getInstantHash(string &s){
        long long ans = 0;
 
        for(auto &c : s){
            ans = (ans * p) % m;
            ans = (ans + (c - 'a' + 1)) % m;
        }
 
        return ans;
    }
};


// double hash
class HashString{
    long long p = 37, m = 1000000021;
    long long p1 = 31, m1 = 1000000241;
    vector<long long> h, ppow;
    vector<long long> h1, ppow1;
    public:
 
    HashString(string &s){
        int n = s.length();
        h.resize(n + 1, 0);
        h1.resize(n + 1, 0);
        ppow.resize(n + 1, 0);
        ppow1.resize(n + 1, 0);
        ppow[0] = 1;
        ppow1[0] = 1;
 
        for(int i = 1; i <= n; ++i){
            ppow[i] = (ppow[i - 1] * p) % m;
            ppow1[i] = (ppow1[i - 1] * p1) % m1;
            h[i] = ((h[i - 1] * p) % m + (s[i - 1] - 'a' + 1)) % m;
            h1[i] = ((h1[i - 1] * p1) % m1 + (s[i - 1] - 'a' + 1)) % m1;
        }
    }
    
    // assume zero based indexing
    pair<long long, long long> getSubHash(int l, int r){ 
        long long ans = (h[r + 1] - (h[l] * ppow[r - l + 1]) % m + m) % m;
        long long ans1 = (h1[r + 1] - (h1[l] * ppow1[r - l + 1]) % m1 + m1) % m1;
        return {ans, ans1};
    }
 
    pair<long long, long long> getInstantHash(string &s){
        long long ans = 0;
        long long ans1 = 0;
 
        for(auto &c : s){
            ans = (ans * p) % m;
            ans1 = (ans1 * p1) % m1;
            ans = (ans + (c - 'a' + 1)) % m;
            ans1 = (ans1 + (c - 'a' + 1)) % m1;
        }
 
        return {ans, ans1};
    }
};