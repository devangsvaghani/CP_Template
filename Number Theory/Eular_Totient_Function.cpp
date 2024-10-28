// Eular totient function O(sqrt(n))
long long singlePhi(long long n){
  long long result = n;
  for(long long i = 2; i * i <= n; ++i){
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

// Eular totient function - Precomputation
const long long phiSize = 1e6 + 1;
long long phi[phiSize];

void preComputePhi(){
  for(long long i = 0; i < phiSize; ++i) phi[i] = i;

  for(long long i = 2; i < phiSize; ++i){
    if(phi[i] == i){
      for(long long j = i; j < phiSize; j += i){
        phi[j] -= phi[j] / i;
      }
    }
  }
}