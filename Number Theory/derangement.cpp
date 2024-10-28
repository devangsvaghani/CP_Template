// Derangement - Permutation such that no element appears in its original position
// D[n] = (D[n - 1] + D[n - 2]) * (n - 1);
// D[1] = 0, D[2] = 1;
const long long derangementSize = 1e6 + 1;
long long derangement[derangementSize];

void preComputeDerangement(){
    derangement[1] = 0;
    derangement[2] = 1;

    for(long long i = 3; i < derangementSize; ++i){
        derangement[i] = (((derangement[i - 1] + derangement[i - 2])) % mod * (i - 1)) % mod;
    }
}