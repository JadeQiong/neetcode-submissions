class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> q;
        for(int i=0;i<gifts.size();i++){
            q.push(gifts[i]);
        }
        while(k){
            long long cur = q.top();
            q.pop();
            q.push(sqrt(cur));
            k--;
        }
        long long ans = 0;
        while(!q.empty()){
            ans += q.top();
            q.pop();
        }
        return ans;
    }
};