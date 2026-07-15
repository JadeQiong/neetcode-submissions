class Solution {
public:
long long power(int base, int exp, int mod) {
        long long result = 1, b = base;
        while (exp > 0) {
            if (exp & 1) result = (result * b) % mod;
            b = (b * b) % mod;
            exp >>= 1;
        }
        return result;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int mod = 1e9+7;
        int r = nums.size()-1;
        for(int i=0;i<nums.size();i++){
            while(i <= r && nums[r] + nums[i] > target){
                r--;
            }
            if(i <= r){
                ans = (ans + power(2, r-i, mod))%mod;
            }
        }
        return ans;
    }
};