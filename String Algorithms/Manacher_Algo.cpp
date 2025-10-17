// Manacher's Algorithm
class Manacher{
    public:
    vector<int> p;

    Manacher(string &s){
        string t = "";
        for(auto &c : s){
            t += '#';
            t += c;
        }
        t += '#';
        run(t);
    }

    void run(string s){
        int n = s.length();
        p.resize(n, 1);

        int l = -1, r = 1;
        for(int i = 1; i < n; ++i){
            if(l + r - i >= 0 && l + r - i < n){
                p[i] = max(0, min(r - i, p[l + r - i]));
            }
            while(i + p[i] < n && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]]){
                p[i]++;
            }
            if(i + p[i] > r){
                l = i - p[i];
                r = i + p[i];
            }
        }
    }

    int getLongest(int cen, bool odd){
        int pos = 2 * cen + 1 + (!odd);
        return p[pos] - 1;
    }

    // 0-based indexing
    bool checkPali(int l, int r){
        if((r - l + 1) <= getLongest((l + r) / 2, l % 2 == r % 2)){
            return true;
        }
        return false;
    }

    /*
        convert center to starting position of palindrome
        start = (cen - len) / 2;
        start = (cen - p[cen] + 1) / 2;
    */
};