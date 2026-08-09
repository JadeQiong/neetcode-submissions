class Solution {
public:
    vector<int> range{1, 7, 30};
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, 0);
        for(int i=n-1;i>=0;i--){
            dp[i]=INT_MAX;
            int j = i;
            for(int k=0;k<range.size();k++){
                while(j < n && days[j] < days[i] + range[k]){
                    j++;
                }
                dp[i] = min(dp[i], dp[j] + costs[k]);
            }
        }
        return dp[0];
    }
};