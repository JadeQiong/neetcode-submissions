class Solution {
public:
    
    int findMaxForm(vector<string>& strs, int m, int k) {
        int n = strs.size();
        vector<vector<int>> arr(n, vector<int>(2));
        for(int i=0;i<n;i++){
            for(auto c: strs[i]){
                arr[i][c-'0']++;
            }
        }
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, 0)));
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                for(int kk=0;kk<=k;kk++){
                    dp[i][j][kk]=dp[i-1][j][kk];
                    if(j>=arr[i-1][0] && kk >= arr[i-1][1]){
                    dp[i][j][kk]=max(dp[i][j][kk], dp[i-1][j-arr[i-1][0]][kk-arr[i-1][1]] + 1);
                    }
                }
            }
        }
        return dp[n][m][k];
    }
};