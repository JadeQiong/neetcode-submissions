class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        map<int, vector<int>> e;
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            e[u].push_back(v);
            e[v].push_back(u);
        }
        return dfs(e, hasApple, 0, -1);
    }
    int dfs(map<int, vector<int>>& mp, vector<bool>& hasApple, int cur, int parent){
        int time = 0;
        for(int nxt: mp[cur]){
            if(nxt == parent) continue;
            int subTime = dfs(mp, hasApple, nxt, cur);
            if(subTime > 0 || hasApple[nxt]){
                time += 2 + subTime;
            }
        }
        return time;
    }
}; 