class Solution {
public:
    unordered_map<int, int> ans;
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        vector<vector<pair<int, int>>> v(n);
        for(auto e:edges){
            int u = e[0];
            int vv = e[1];
            int w = e[2];
            v[u].push_back({ vv, w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, src});
        while(!q.empty()){
            auto cur = q.top();
            q.pop();
            if(ans.count(cur.second)) continue;
            ans[cur.second] = cur.first;

            for(auto p: v[cur.second]){
                if(!ans.count(p.first)){
                    q.push({cur.first + p.second, p.first});
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!ans.count(i)){
                ans[i] = -1;
            }
        }
    return ans;    
    }
};
