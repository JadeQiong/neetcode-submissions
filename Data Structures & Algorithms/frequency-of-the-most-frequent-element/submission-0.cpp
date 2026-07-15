class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
       sort(nums.begin(), nums.end());
       int n = nums.size();
       vector<long long> prefixSum(n+1, 0);
       for(int i=0;i<n;i++){
        prefixSum[i+1] = nums[i] + prefixSum[i];
       } 

       int res=1;
       for(int i=0;i<n;i++){
        int l=0, r = i;
        while(l<=r){
            int mid = (l+r)/2;
            long long curSum = prefixSum[i+1]-prefixSum[mid];
            long long need = (i-mid+1)*1LL*nums[i]-curSum;
            if(need <= k){
                r = mid-1;
                res = max(res, i-mid+1);
            } else {
                l=mid+1;
            }
        }
       }
       return res;
    }
};