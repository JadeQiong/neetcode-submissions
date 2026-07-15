class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<int> indexes(n);
        for(int i=0;i<n;i++){
            indexes[i]=i;
        }
        sort(indexes.begin(), indexes.end(), [&](int a, int b){
            return capital[a] < capital[b];
        });

        priority_queue<int> q;
        int idx = 0;
        for(int i=0;i<k;i++){
            while(idx < n && capital[indexes[idx]] <= w){
                q.push(profits[indexes[idx]]);
                idx++;
            }
            if(q.empty()) break;
            auto cur = q.top();
          
            w += cur;
            q.pop();
        }
        return w;
    }
};