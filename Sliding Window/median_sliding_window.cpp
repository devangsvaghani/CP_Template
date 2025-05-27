class MedianSlidingWindow {
    public:
    multiset<long long> st1, st2;
    long long len;

    MedianSlidingWindow(){
        len = 0;
    }

    void add(long long x){
        st2.insert(x);
        ++len;

        st1.insert(*st2.begin());
        st2.erase(st2.begin());

        while((long long)st1.size() > (len / 2)){
            st2.insert(*st1.rbegin());
            st1.erase(--st1.end());
        }
    }

    void remove(long long x){
        auto it = st2.find(x);
        if(it != st2.end()){
            st2.erase(it);
            --len;

            while((long long)st1.size() > (len / 2)){
                st2.insert(*st1.rbegin());
                st1.erase(--st1.end());
            }
            return;
        }

        it = st1.find(x);
        if(it != st1.end()){
            st1.erase(it);
            --len;

            while((long long)st1.size() < (len / 2)){
                st1.insert(*st2.begin());
                st2.erase(st2.begin());
            }
            return;
        }
    }

    long long getMedian(){
        if(len & 1){
            return *st2.begin();
        }else{
            return *st1.rbegin();
        }
    }

    // double getMedian(){
    //     if(len & 1){
    //         return *st2.begin();
    //     }else{
    //         return (double)(*st1.rbegin() + *st2.begin()) / 2;
    //     }
    // }
};