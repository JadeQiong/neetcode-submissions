class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int r, int c, vector<vector<char>>& matrix){
        if(r >= matrix.size() || c >= matrix[0].size()){
            return 0;
        }
        if(dp[r][c]!=-1) return dp[r][c];
        int right = dfs(r, c+1, matrix);
        int down = dfs(r+1, c, matrix);
        int diag = dfs(r+1, c+1, matrix);
        dp[r][c]=0;
        if(matrix[r][c] == '1'){
            dp[r][c] = 1 + min(right, min(down, diag));
        }
        return dp[r][c];
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        dp.resize(r, vector<int>(c, -1));
        dfs(0, 0, matrix);
        int ans = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans = max(ans, dp[i][j]*dp[i][j]);
            }
        }
        return ans;
    }
};