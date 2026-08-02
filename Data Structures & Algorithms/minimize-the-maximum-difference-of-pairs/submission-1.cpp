class Solution {
public:
    int n;
    unordered_map<long long, int> dp;
    int dfs(int i, int pairs, vector<int>& nums, int p){
        if(pairs == p) return 0;
        if(i>=n-1) return INT_MAX;
        long long key = i;
        key = (key << 31) | pairs;
        if(dp.count(key)) return dp[key];
        int take = max(nums[i+1]-nums[i], dfs(i+2, pairs+1, nums, p));
        int skip = dfs(i+1, pairs, nums, p);
        return dp[key]=min(take, skip);
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        return dfs(0, 0, nums, p);
    }
};