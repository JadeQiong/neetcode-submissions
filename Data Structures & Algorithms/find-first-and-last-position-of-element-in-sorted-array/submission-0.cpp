class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool leftBias){
        int l = 0, r = nums.size()-1;
        int ans = -1;
        while(l<=r){
            int mid = (l+r)/2;
            if(target > nums[mid]){
                l = mid+1;
            }else if(target < nums[mid]){
                r = mid-1;
            }else{
                ans = mid;
                if(leftBias){
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {binarySearch(nums, target, true), binarySearch(nums, target, false)};
    }
};