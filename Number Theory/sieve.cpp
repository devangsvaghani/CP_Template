// Sieve for prime numbers
const long long sieveSize = 1e7+1;
bool prime[sieveSize];
vector<long long> primes;

void preComputeSieve(){
    for(long long i = 2; i < sieveSize; ++i) prime[i] = true;
    for(long long i = 2; i < sieveSize; ++i){
        if(prime[i]){
                primes.push_back(i);
            for(long long j = i * i; j < sieveSize; j += i){
                prime[j] = false;
            }
        }
    }
}


// Optimised Sieve specially for N = 1e8
const long long sieveSize = 1e8+1;
bool prime[sieveSize];
vector<long long> ps;

void sieve(){
    for(long long i = 0; i < sieveSize; i++) prime[i] = true;
    for(long long i = 3; i * i < sieveSize; i += 2){
        if(prime[i / 2]){
            for(long long j = i * i; j < sieveSize; j += i * 2){
                prime[j / 2] = false;
            }
        }
    }

    ps.push_back(2);
    for(long long i = 3; i < sieveSize; i += 2){
        if(prime[i / 2]){
            ps.push_back(i);
        }
    }
}