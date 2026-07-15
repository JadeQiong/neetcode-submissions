class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0, res = 0;
        map<int, int> count;
        count[0]=1;
        for(auto num:nums){
            sum += num;
            res += count[sum-goal];
            count[sum]++;
        }
        return res;
    }
};