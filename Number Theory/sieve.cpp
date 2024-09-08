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



// Optimised Sieve specially for N = 1e8
const ll N = 1e8+1;
bool prime[N];
vector<int> ps;

void sieve(){
    for(ll i = 0; i < N; i++) prime[i] = true;
    for(ll i = 3; i * i < N; i += 2){
        if(prime[i / 2]){
            for(ll j = i * i; j < N; j += i * 2){
                prime[j / 2] = false;
            }
        }
    }

    ps.push_back(2);
    for(ll i = 3; i < N; i += 2){
        if(prime[i / 2]){
            ps.push_back(i);
        }
    }
}