class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int cur = 0;
        for(int i=0;i<n;i++){
            if(i < minutes) {
                cur += customers[i];
            } else 
            cur += (1-grumpy[i])*customers[i];
        }
        int ans = cur;
        for(int i=minutes;i<n;i++){
            if(grumpy[i]){
                cur += customers[i];
            }
            if(grumpy[i-minutes]){
                cur -= customers[i-minutes];
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};