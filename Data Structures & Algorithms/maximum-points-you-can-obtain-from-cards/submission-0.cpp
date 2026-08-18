class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = 0;
        int n = cardPoints.size();
        if(k >= n){
            int sum = 0;
            for(auto num:cardPoints){
                sum += num;
            }
            return sum;
        }
        vector<int> pre(k+1);
        vector<int> post(k+1);
        for(int i=1;i<=k;i++){
            pre[i] = pre[i-1]+cardPoints[i-1];
        }
        for(int i=1;i<=k;i++){
            post[i] = post[i-1]+cardPoints[n-i];
        }
        for(int i=0;i<=k;i++){
            ans = max(ans, pre[i] + post[k-i]);
        }
        return ans;
    }
};