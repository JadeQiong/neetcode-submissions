class Solution {
public:
    vector<bool> vis;
    map<int, vector<int>> g;
    bool ans = true;
    void dfs(int x, int last){
        vis[x] =1;
        for(auto nxt:g[x]){
            if(!vis[nxt]){
                dfs(nxt, x);
            } else {
                if(nxt != last){
                    ans = false;
                    return;
                }
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vis.resize(n);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0, -1);
        if(!ans) return false;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};
