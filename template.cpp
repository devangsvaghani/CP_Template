#include <bits/stdc++.h>

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#include "dev/debug.hpp"
#else
#define debug(...) 8
#endif

#define devangsvaghani ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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
const ll inf = 1e18;
const ll N = 1e5+5;



bool sortbysec(const pair<int,int> &a,const pair<int,int> &b) { return (a.second < b.second); }
ll power(ll n,ll a){ ll res=1; while(a){ if(a%2) res*=n,a--; else   n*=n,a/=2;} return res;}
ll modpower(ll n,ll a,ll p){ ll res=1; while(a){ if(a%2) res= ((res*n)%p) ,a--; else n=((n*n)%p),a/=2;} return res;}
ll fastprime(ll a){ if (((a != 2) && (a % 2 == 0)) || (a < 2)) return 0;  for(ll i = 3; i * i <= a; i += 2) if(a % i == 0) return 0; return 1;}
ll mod_mul_inverse(ll a,ll b) {return modpower(a , b-2, b);}
ll gcd(ll a, ll b){return (b == 0 ? a : gcd(b, a % b));}

void init(){

}

void solve(){
  
}

int main() {
  devangsvaghani;

  // init();
  
  ll t = 1;
  cin >> t;
  for (ll T = 1; T <= t; T++) {
    // cout << "Case #" << T << ": ";
    solve();
  }
  return 0;
}