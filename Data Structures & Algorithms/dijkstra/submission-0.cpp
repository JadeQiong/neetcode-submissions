class Solution {
public:
    unordered_map<int, int> ans;
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        vector<vector<pair<int, int>>> g(n);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            g[u].push_back({v, weight});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, src});
        while(!q.empty()){
            auto cur = q.top();
            q.pop();
            if(ans.find(cur.second) != ans.end()){
                continue;
            }
            ans[cur.second] = cur.first;
            for(auto e: g[cur.second]){
                int nxt = e.first;
                int w = e.second;
                if(ans.find(nxt) == ans.end()){
                    q.push({w+cur.first, nxt});
                }
            }
        }
        for(int i=0;i<n;i++){
            if(ans.find(i) == ans.end()){
                ans[i] = -1;
            }
        }
    return ans;    
    }
};
