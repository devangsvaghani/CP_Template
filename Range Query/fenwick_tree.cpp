// Fenwick Tree (Binary Indexed Tree)
// 1 - based indexing 
struct BIT {
    long long n;
    vector<long long> bit;
    FenwickTree(int n) : bit(n), n(n) {}

    // v[pos] += dif
    void update(int pos, long long dif) { 
        for (; pos < n; pos += (pos & -pos)) bit[pos] += dif;
    }

    // sum of values in [1, pos]
    long long query(int pos) { 
        long long res = 0;
        for (; pos > 0; pos -= (pos & -pos)) res += bit[pos];
        return res;
    }
};