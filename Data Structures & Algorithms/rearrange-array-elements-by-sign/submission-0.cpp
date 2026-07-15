class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int p1 = 0, p2 = 1;
        for(int i=0;i<n;i++){
            if(nums[i] > 0){
                ans[p1] = nums[i];
                p1+=2;
            } else {
                ans[p2] = nums[i];
                p2 += 2;
            }
        }
        return ans;
    }
};