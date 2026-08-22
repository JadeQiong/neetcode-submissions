class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size();
        while(l<=r){
            int mid = (l+r)/2;
            if(mid-1 >= 0 && nums[mid] < nums[mid-1]){
                r = mid-1;
            } else if(mid+1 < nums.size() && nums[mid] < nums[mid+1]){
                l = mid+1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};