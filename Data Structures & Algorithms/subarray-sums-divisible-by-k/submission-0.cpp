class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int, int> mp;
        int sum = 0;
        int ans = 0;
        mp[0]=1;
        for(auto num:nums){
            sum += num;
            if(mp.count(sum % k)){
                ans += mp[sum % k];
            }
            mp[sum%k]++;
        }
        return ans;
    }
};