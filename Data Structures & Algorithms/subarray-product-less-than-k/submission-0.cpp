class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        long long cur = 1;
        int ans = 0;
        while(l<=r && r < n){
            cur *= nums[r];
            while(cur >= k && l <= r){
                cur /= nums[l++];
            }
            ans += r-l+1;
            r++;
        }
        return ans;
    }
};