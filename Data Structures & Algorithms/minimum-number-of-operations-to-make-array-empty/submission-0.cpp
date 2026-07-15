class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto num:nums){
            mp[num]++;
        }
        //3*i+2*j
        int ans = 0;
        for(auto& [k, v]: mp){
          if(v == 1) return -1;
          ans += (v+2)/3;
        }
        return ans;
    }
};