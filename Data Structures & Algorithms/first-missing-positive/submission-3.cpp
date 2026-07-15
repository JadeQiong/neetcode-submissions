class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] <= 0){
                nums[i] = n+1;
            }
        }
        for(int i=0;i<n;i++){
            int absval = abs(nums[i]);
            if(absval >=1 && absval <= n){
                int val = absval -1;
                if(nums[val] > 0){
                    nums[val]=-nums[val];
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     cout << nums[i] << " ";
        // }
        // cout << endl;
        for(int i=0;i<n;i++){
            if(nums[i] > 0) return i+1;
        }
        return n+1;
    }
};