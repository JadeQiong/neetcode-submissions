/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l = 1, r = n-2;
        int peak = 0;
        while(l <= r){
            int mid = l + (r-l)/2.0;
            int val = mountainArr.get(mid);
            int right = mountainArr.get(mid+1);
            int left = mountainArr.get(mid-1);
            if(left < val && val < right){
                l = mid + 1;
            } else if(left > val && val > right){
                r = mid - 1;
            } else {
                peak = mid;
                break;
            }
        }

        l = 0, r = peak-1;
        while(l<=r){
            int mid = (l+r)/2;
            int val = mountainArr.get(mid);
            if(val < target){
                l = mid + 1;
            } else if(val > target){
                r = mid - 1;
            } else {
                return mid;
            }
        }

        l = peak;
        r = n-1;
        while(l<=r){
            int mid = (l+r)/2;
            int val = mountainArr.get(mid);
            if(val > target){
                l = mid + 1;
            } else if(val < target){
                r = mid - 1;
            } else{
                return mid;
            }
        }
        return -1;
    }
};