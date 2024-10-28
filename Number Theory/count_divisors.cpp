// Count number of divisors
const long long divisorSize = 1e6 + 1;
long long divisorsCnt[divisorSize];

void preComputeDivisorsCnt(){
    divisorsCnt[0] = 1;

    for (long long i = 1; i * i < N; ++i){
        divisorsCnt[i * i]--;
        for (long long j = (i * i); j < N; j += i){
            divisorsCnt[j] += 2;
        }
    }
}

bool isPrime(long long n){
    return (bool)(divisorsCnt[n] == 2);
}