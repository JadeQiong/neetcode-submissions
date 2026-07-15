class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> ans;
        int n = heights.size();
        int maxHeight = -1;
        for(int i=n-1;i>=0;i--){
            if(heights[i] > maxHeight){
                ans.push_back(i);
            }
            maxHeight = max(maxHeight, heights[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};