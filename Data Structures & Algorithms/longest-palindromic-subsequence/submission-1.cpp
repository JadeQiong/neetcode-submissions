class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int i, int j, string& s){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i == j){
            return dp[i][j]=1;
        }
        if(s[i] == s[j]){
            dp[i][j]=dfs(i+1, j-1, s) + 2;
        } else {
            dp[i][j]=max(dfs(i+1, j, s), dfs(i, j-1, s));
        }
        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        dp.resize(n, vector<int>(n, -1));
        dfs(0, n-1, s);
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};