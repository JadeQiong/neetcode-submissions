class Solution {
public:
    vector<vector<int>> cache;
    int n;
    vector<int> dfs(int i, vector<int>& nums){
        if(cache[i].size()) {
            return cache[i];
        }
        vector<int> res = {nums[i]};
        for(int j=i+1;j<n;j++){
            if(nums[j]%nums[i]==0){
                vector<int> tmp = {nums[i]};
                vector<int> nxt = dfs(j, nums);
                tmp.insert(tmp.end(), nxt.begin(), nxt.end());
                if(tmp.size() > res.size()){
                    res = tmp;
                }
                
            }
        }
        return res;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        cache.resize(n, vector<int>());
        dfs(0, nums);
        vector<int> res;
        for(int i=0;i<n;i++){
            vector<int> tmp = dfs(i, nums);
            if(tmp.size() > res.size()){
                res = tmp;
            }
        }
        return res;
    }
};