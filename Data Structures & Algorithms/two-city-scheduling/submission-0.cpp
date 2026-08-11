class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size()/2;
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
        dp[0][0]=0;
        for(int aCount=0; aCount<=n;aCount++){
            for(int bCount=0;bCount<=n; bCount++){
                int i = aCount + bCount;
                if(aCount >= 1){
                    dp[aCount][bCount] = min(dp[aCount-1][bCount] + costs[i-1][0], dp[aCount][bCount]);
                }
                if(bCount >= 1){
                    dp[aCount][bCount] = min(dp[aCount][bCount], dp[aCount][bCount-1] + costs[i-1][1]);
                }

            }
        }
        return dp[n][n];
    }
};