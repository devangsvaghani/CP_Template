// Fenwick Tree
struct FenwickTree {
    long long n;
    vector<long long> s;
    FenwickTree(int n) : s(n), n(n) {}

    // v[pos] += dif
    void update(int pos, long long dif) { 
        for (; pos < n; pos += (pos & -pos)) s[pos] += dif;
    }

    // sum of values in [1, pos]
    long long query(int pos) { 
        long long res = 0;
        for (; pos > 0; pos -= (pos & -pos)) res += s[pos];
        return res;
    }
};