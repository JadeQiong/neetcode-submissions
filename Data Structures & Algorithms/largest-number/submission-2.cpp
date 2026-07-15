class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans;
        sort(nums.begin(), nums.end(), [&](int a, int b){
            return to_string(a)+to_string(b) > to_string(b)+to_string(a);
        });
        bool ok = false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]){
                ok = true;
            }
            if(ok)
            ans += to_string(nums[i]);
        }
        if(ans.size() == 0) return "0";
        return ans;
    }
};