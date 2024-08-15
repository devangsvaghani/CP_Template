// Sieve 
int count_divisors[N];
void f_count_divisors(){
    count_divisors[0] = 1;
    for(ll i = 1; i * i < N; ++i){
        count_divisors[i * i]--;
        for(ll j = i * i; j < N; j += i){
            count_divisors[j] += 2;
        }
    }
}
bool isPrime(ll x){
    return (count_divisors[x] == 2);
}