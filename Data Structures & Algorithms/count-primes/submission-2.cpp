class Solution {
public:
    int countPrimes(int n) {
        vector<bool> v(n+1, false);
        int ans = 0;
        for(int i=2;i<n;i++){
            if(!v[i]){
                ans++;
                for(long long num=1LL*i*i; num<n; num += i){
                    v[num] = true;
                }
            }
        }
        return ans;
    }
};