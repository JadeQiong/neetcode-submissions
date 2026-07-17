class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int ans = 0;
       int l = 0, r = 0;
       int cnt = 0;
       int n = nums.size();
       for(int i=0;i<min(k, n);i++){
        if(nums[i] == 0){
            cnt++;
        }
        ans++;
       } 
       r = min(n, k);
       while(r < n && l <= r){
        if(nums[r] == 0){
            cnt++;
        }
        while(cnt > k && l<=r){
            cnt -= (1-nums[l++]);
        }
        ans = max(ans, r - l + 1);
        r++;        
       }
       return ans;
    }
};