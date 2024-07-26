ll single_phi(ll n){
  ll result = n;
  for(ll i = 2; i * i <= n; ++i){
    if(n % i == 0){
      while(n % i == 0) n /= i;
      result -= result / i;
    }
  }

  if(n > 1){
    result -= result / n;
  }
  return result;
}

ll phi[N];
void f_phi(){
  for(ll i = 0; i < N; ++i) phi[i] = i;

  for(ll i = 2; i < N; ++i){
    if(phi[i] == i){
      for(ll j = i; j < N; j += i){
        phi[j] -= phi[j] / i;
      }
    }
  }
}