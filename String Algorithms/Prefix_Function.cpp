vector<ll> buildPrefix(vector<ll> &v, ll n){
  vector<ll> pi(n);
  pi[0] = 0;
  f(i, 1, n){
    ll j = pi[i-1];
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