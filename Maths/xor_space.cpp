vector<int> basis(30, 0); // assuming all elements are < 2^30
int cnt = 0;

// insert an element into vector space
auto insert = [&](int x) -> void{
    for(int i = 29; i >= 0; --i){
        if((x >> i) & 1){
            if(basis[i] == 0){
                basis[i] = x;
                ++cnt;
                return;
            }

            x ^= basis[i];
        }
    }
};

// query to find kth largest element in the all possible subset xors
auto query = [&](int k) -> int{
    int mask = 0;
    int total = (1 << cnt);

    for(int i = 29; i >= 0; --i){
        if(basis[i] == 0) continue;

        int low = total / 2;

        if((low < k && ((mask >> i) & 1) == 0) || (low >= k && ((mask >> i) & 1) == 1)){
            mask ^= basis[i];
        }

        if(low < k){
            k -= low;
        }

        total /= 2;
    }

    return mask;
};


// the number of subsequences such that xor sum is x
// ANS: if x is linear combination of current basis then the answer is 2 ^ (n - cnt)
// n -> total number of elements
// cnt -> no. of elements in the basis

// eg. look at https://codeforces.com/contest/959/problem/F

// to check whether x is in the current vector space or not
auto check = [&](int x) -> bool{
    for(int i = 29; i >= 0; --i){
        if((x >> i) & 1){
            if(basis[i] == 0) return false;
            x ^= basis[i];
        }
    }

    return true;
};