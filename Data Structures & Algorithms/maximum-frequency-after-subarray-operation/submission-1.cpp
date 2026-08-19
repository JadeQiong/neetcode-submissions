class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        map<int, int> mp;
        int res = 0;
        for(auto num:nums){
            int maxBefore = max(mp[num], mp[k]);
            mp[num] = maxBefore + 1;
            res = max(res, mp[num] - mp[k]);
        }
        return res + mp[k];
    }
};