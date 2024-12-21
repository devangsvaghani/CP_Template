// FFT - Fast Fourier Transform
// Multiply two polynomials in O(n log n)
class FFT{
 
    const double PI = acos(-1);
    struct base{
 
        double a, b;
        base(double a = 0, double b = 0) : a(a), b(b) {}
        const base operator+(const base &c) const {
            return base(a + c.a, b + c.b);
        }
        const base operator-(const base &c) const {
            return base(a - c.a, b - c.b);
        }
        const base operator*(const base &c) const {
            return base(a * c.a - b * c.b, a * c.b + b * c.a);
        }
    };
 
    public:
 
    void fft(vector<base> &p, bool inv = 0){
        int n = p.size(), i = 0;
 
        // bit reverse permutation
        for (int j = 1; j < n - 1; ++j){
            for (int k = n >> 1; k > (i ^= k); k >>= 1);
            if (j < i) swap(p[i], p[j]);
        }
 
        for (int len = 2, l = 1; len <= n; len <<= 1, l <<= 1){
            double ang = 2 * PI / len;
            base wn = base(cos(ang), (inv ? 1. : -1.) * sin(ang)), w;
            for (int i = 0, j; i < n; i += len){
                for (w = base(1, 0), j = i; j < i + l; ++j, w = w * wn)
                {
                    base t = w * p[j + l];
                    p[j + l] = p[j] - t;
                    p[j] = p[j] + t;
                }
            }
        }
 
        if (inv){
            for (int i = 0; i < n; ++i){
                p[i].a /= n, p[i].b /= n;
            }
        }       
    }
 
    vector<long long> multiply(vector<long long> &a, vector<long long> &b){
        int n = a.size(), m = b.size(), sz = 1;
        while (sz < n + m - 1) sz <<= 1;
        vector<base> x(sz), y(sz), z(sz);
        for (int i = 0; i < sz; ++i){
            x[i] = i < n ? base(a[i], 0) : base(0, 0);
            y[i] = i < m ? base(b[i], 0) : base(0, 0);
        }
        fft(x), fft(y);
        for (int i = 0; i < sz; ++i) z[i] = x[i] * y[i];
        fft(z, 1);
 
        vector<long long> ret(n + m - 1);
        for (int i = 0; i < n + m - 1; ++i) ret[i] = (long long)round(z[i].a);
        return ret;
    }
};