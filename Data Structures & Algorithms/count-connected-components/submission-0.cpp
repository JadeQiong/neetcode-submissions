class Solution {
public:
    map<int, vector<int>> g;
    vector<bool> vis;
    void dfs(int x){
        vis[x]=1;
        for(auto nxt:g[x]){
            if(!vis[nxt])
            dfs(nxt);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vis.resize(n);
        for(auto pair:edges){
            int u = pair[0], v = pair[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i);
                ans++;
            }
        }
        return ans;
    }
};
