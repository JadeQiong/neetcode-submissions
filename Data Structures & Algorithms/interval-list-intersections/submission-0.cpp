class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        sort(firstList.begin(), firstList.end());
        sort(secondList.begin(), secondList.end());
        int n = firstList.size();
        int m = secondList.size();
        int i=0, j=0;
        while(i<n && j<m){
           int left = max(firstList[i][0], secondList[j][0]);
           int right = min(firstList[i][1], secondList[j][1]);
           if(right >= left){
            ans.push_back(vector<int>{left, right});
           }
           if(firstList[i][1] >= secondList[j][1]){
            j++;
           } else {
            i++;
           }
        }
        return ans;
    }
};