class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        for(auto num:nums){
            sum += num;
        }
        if(sum % p == 0) return 0;
        int remainder = sum % p;
        long long curSum = 0;
        map<int, int> mp;
        mp[0]=-1;
        int ans = nums.size();
        for(int i=0;i<nums.size();i++){
            curSum = (curSum + nums[i])%p;
            int t=(curSum-remainder+p)%p;
            if(mp.count(t)){
                ans = min(ans, i-mp[t]);
            }
            mp[curSum]=i;
        }
        return ans == nums.size() ? -1: ans;
    }
};