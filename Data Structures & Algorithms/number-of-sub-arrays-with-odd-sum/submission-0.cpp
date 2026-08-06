class Solution {
public:
    int mod = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        long long res = 0;
        int evenCount = 0, oddCount = 0;
        long long sum = 0;
        for(auto num:arr){
            sum += num;
            if(sum&1){
                res = (res + 1 + evenCount)%mod;
                oddCount++;
            } else {   
                res = (res + oddCount)%mod;
                evenCount++;
            }
        }
        return res;
    }
};