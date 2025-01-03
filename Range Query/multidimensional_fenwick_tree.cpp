// Multidimensional Fenwick Tree (Binary Indexed Tree)

/*
Usage:

For 1D BIT:
BIT<ll, 200005> bit;
bit.update(x, 1); // increment at index x by 1.
bit.query(x); // sum of elements from 1 to x.

For 2D BIT:
BIT<ll, 1000, 1000> bit;
bit.update(x1, y1, 1); // increment at (x1, y1) by 1.
bit.query(y1, y2, x1, x2) // sum of rectangle from (x1, y1) to (x2, y2).
*/

template <class T, int... Ns> struct BIT {
    T val = 0;
    void update(T v) { val += v; }
    T query() { return val; }
};

template <class T, int N, int... Ns> struct BIT<T, N, Ns...> {
    BIT<T, Ns...> bit[N + 1];
    template <typename... Args> void update(int pos, Args... args) {
        for (; pos <= N; pos += (pos & -pos)) bit[pos].update(args...);
    }
    template <typename... Args> T sum(int r, Args... args) {
        T res = 0;
        for (; r; r -= (r & -r)) res += bit[r].query(args...);
        return res;
    }
    template <typename... Args> T query(int l, int r, Args... args) {
        return sum(r, args...) - sum(l - 1, args...);
    }
};