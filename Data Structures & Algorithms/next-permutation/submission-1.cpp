class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1;
        for(int i=0;i<nums.size();i++){
            if(i+1 < nums.size() && nums[i]<nums[i+1]){
                pivot = i;
            }
        }
        if(pivot == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = nums.size()-1;
        while(nums[j] <= nums[pivot]){
            j--;
        }
        
        swap(nums[pivot], nums[j]);
        sort(nums.begin() + pivot+1, nums.end());
        return;
    }
};