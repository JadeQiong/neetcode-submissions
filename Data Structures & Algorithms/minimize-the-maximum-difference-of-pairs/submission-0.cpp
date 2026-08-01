class Solution {
public:
    int n;
    bool ok(int t, vector<int>& nums, int p){
        int i = 0;
        int count = 0;
        while(i<n-1){
            if(i+1 < n && nums[i+1]-nums[i] <= t){
                count++;
                i+=2;             
            } else {
                i++;
            }
        }
        return count >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        int l = 0, r = nums[n-1]-nums[0];
        int ans = r;
        while(l<=r){
            int mid = (l+r)/2;
            if(ok(mid, nums, p)){
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};