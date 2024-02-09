vector<ll> z_function(string &s, ll n){
  vector<ll> z(n);
  z[0] = 0;
  ll l = 0, r = 0;
  f(i, 1, n){
    if(i < r){
      z[i] = min(r - i, z[i - l]);
    }
    while(i + z[i] < n && s[z[i]] == s[i + z[i]]){
      z[i]++;
    }
    if(i + z[i] > r){
      l = i;
      r = i + z[i];
    }
  }
  return z;
}