class Solution {
public:
    vector<double> dp;
    double dfs(int score, int n, int k, int maxPts){
        if(score >= k){
            return score <= n ? 1 : 0;
        }
        if(dp[score]!=-1) return dp[score];
        double prob = 0;
        for(int i=1;i<=maxPts; i++){
            prob += dfs(score+i, n, k, maxPts);
        }
        return dp[score] = prob/maxPts;
    }
    double new21Game(int n, int k, int maxPts) {
        dp.resize(k, -1);
        return dfs(0, n, k, maxPts);
    }
};