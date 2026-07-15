class Solution {
public:
    unordered_map<int, vector<pair<int, double>>> g;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        for(int i=0;i<edges.size();i++){
            auto edge = edges[i];
            int u = edge[0];
            int v = edge[1];
            g[u].push_back({v, succProb[i]});
            g[v].push_back({u, succProb[i]});
        }
        vector<double> dis(n, 0);
        dis[start_node] = 1;
        priority_queue<pair<double, int>> q;
        q.push({1.0, start_node});
        double ans = 0;
        while(!q.empty()){
            auto cur = q.top();
            q.pop();
            if (cur.first < dis[cur.second]) continue;
            if(cur.second == end_node){
                return cur.first;
            }
            for(auto [nxt, p]: g[cur.second]){
                if(dis[nxt] == 0){
                    dis[nxt] = cur.first * p;
                    q.push({dis[nxt], nxt});
                } else if(dis[nxt] < p * cur.first){
                    dis[nxt] = p * cur.first;
                    q.push({dis[nxt], nxt});
                }
            }
        }
        return ans;
    }
};