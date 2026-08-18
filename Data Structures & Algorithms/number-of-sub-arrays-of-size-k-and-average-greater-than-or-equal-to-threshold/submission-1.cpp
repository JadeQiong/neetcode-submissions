class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        vector<int> prefixSum(n+1);
        for(int i=1;i<=n;i++){
            prefixSum[i] = prefixSum[i-1] + arr[i-1];
        }
        int ans = 0;
        int l = 1;
        for(int r = k; r <= n; r++){
            int sum = prefixSum[r] - prefixSum[l-1];
            if(sum >= k * threshold ){
                ans++;
            }
            l++;
        }
        return ans;
    }
};