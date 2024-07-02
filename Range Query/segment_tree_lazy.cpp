#include <bits/stdc++.h>

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

// #ifndef ONLINE_JUDGE
// #include "dev/debug.hpp"
// #else
// #define debug(...) 8
// #endif

#define DSV ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define yes cout << "YES\n";
#define no cout << "NO\n";
#define f(i, x, n)       for (ll i = x; i < n; i++)
#define rf(i, x, n)      for (ll i = x; i >= n; i--)

const ll mod = 1e9+7;
const ll mod2 = 998244353;
const ll N = 1e6+5;

void init(){

}

// change segNode according to your requirements
struct segNode{
  ll andd, orr;

  segNode(){
    andd = (1ll << 32) - 1;
    orr = 0;
  }

  segNode(ll x){
    andd = x;
    orr = 0;
  }

  void merge(segNode &a, segNode &b){
    andd = a.andd & b.andd;
  }

  void lazy_add(ll x){
    orr |= x;
  }

  void lazy_apply(){
    andd = andd | orr;
  }

  void lazy_merge(segNode &par){
    orr |= par.orr;
  }

  void remove_lazy(){
    orr = 0;
  }
};

class segTree{
  vector<segNode> tree;
  ll n;

  public:

  segTree(ll n){
    this -> n = n;
    tree.resize(4 * n, segNode());

    build(0, 0, n-1);
  }

  void build(ll node, ll l, ll r){
    if(l == r){
      tree[node] = segNode(0);
      return;
    }

    ll mid = l + (r - l)/2;
    build(2 * node + 1, l, mid);
    build(2 * node + 2, mid + 1, r);

    tree[node].merge(tree[2 * node + 1], tree[2 * node + 2]);
  }

  void push(ll node, ll l, ll r){
    tree[node].lazy_apply();

    if(l != r){
      tree[2 * node + 1].lazy_merge(tree[node]);
      tree[2 * node + 2].lazy_merge(tree[node]);
    }

    tree[node].remove_lazy();
  }

  void update(ll s, ll e, ll x){
    update(0, 0, n-1, s, e, x);
  }

  void update(ll node, ll l, ll r, ll s, ll e, ll x){
    push(node, l, r);
    
    if(l > e || r < s) return;
    if(l >= s && r <= e){
      tree[node].lazy_add(x);
      push(node, l, r);
      return;
    }

    ll mid = l + (r - l)/2;
    update(2 * node + 1, l, mid, s, e, x);
    update(2 * node + 2, mid + 1, r, s, e, x);

    tree[node].merge(tree[2 * node + 1], tree[2 * node + 2]);
  }

  // change return type according to question
  ll query(ll s, ll e){
    segNode ans = query(0, 0, n-1, s, e);
    return ans.andd;
  }

  segNode query(ll node, ll l, ll r, ll s, ll e){
    push(node, l, r);

    if(l > e || r < s) return segNode();
    if(l >= s && r <= e) return tree[node];

    ll mid = l + (r - l)/2;

    segNode ans, left, right;
    left = query(2 * node + 1, l, mid, s, e);
    right = query(2 * node + 2, mid + 1, r, s, e);

    ans.merge(left, right);
    return ans;
  }
};

void solve(){
  ll n, q;
  cin >> n >> q;

  segTree sg(n);

  ll a, b, c, d;

  while(q--){
    cin >> a;

    if(a == 1){
      cin >> b >> c >> d;

      sg.update(b, c-1, d);
    }else{
      cin >> b >> c;

      cout << sg.query(b, c-1) << "\n";
    }
  }
}

int main() {
  DSV;

  // #ifndef ONLINE_JUDGE
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", stdout);
  //   freopen("Error.txt", "w", stderr);
  // #endif

  // init();
  
  ll t = 1;
  // cin >> t;
  for (ll T = 1; T <= t; T++) {
    // debug(T);
    solve();
  }
  return 0;
}
