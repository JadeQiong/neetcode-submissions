class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int, int> mp;
        int dominant = -1;
        for(auto num:nums){
            mp[num]++;
            if(mp[num] > nums.size()/2){
                dominant = num;
            }
        }
        cout << "dominant = " << dominant << endl;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == dominant){
                cnt++;
                if(cnt * 2 > (i+1) && (mp[dominant] - cnt) * 2 > (nums.size()-i-1)){
                    return i;
                }
            }
        }
        return -1;
    }
};