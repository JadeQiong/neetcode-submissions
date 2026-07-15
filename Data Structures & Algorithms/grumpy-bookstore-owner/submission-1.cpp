class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += (1-grumpy[i])*customers[i];
        }
        
        int cur = sum;
        for(int i=0;i<minutes;i++){
            if(grumpy[i]){
                cur += customers[i];
            }
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