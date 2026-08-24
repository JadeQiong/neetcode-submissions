class Solution {
public:
    int countPrimes(int n) {
        vector<bool> sieve(n, false);
        int res = 0;
        for(int num=2;num<n;num++){
            if(!sieve[num]){
                res++;
                for(long long i=1LL*num*num; i<n; i+= num) {
                    sieve[i]=true;
                }
            }
        }
        return res;
    }
};