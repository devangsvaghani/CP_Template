template <typename T>
class fenwick {
  public:
	vector<T> fenw;
	int n;
	const T neutral = 0; // Neutral element
	fenwick(int _n) : n(_n) {
		fenw.resize(n,neutral);
	}
	void add(int x, T v) {
		assert(x < n && x >= 0);
		while (x < n) {
			combine(fenw[x],v);
			x |= (x + 1);
		}
	}
	T find(int x) {
		assert(x < n && x >= 0);
		T v = neutral;
		while (x >= 0) {
			combine(v,fenw[x]);
			x = (x & (x + 1)) - 1;
		}
		return v;
	}
	T find(int l,int r) { // Don't forget to change this if using anything other than addition
		return find(r) - (l == 0 ? neutral : find(l-1));
	}
	void combine(T &v, T val){
		v += val;
	}
};