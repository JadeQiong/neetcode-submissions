class Solution {
public:
    int nxt[4][2]={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;
    void bfs(vector<vector<int>>& grid, int x, int y){
        queue<pair<int, int>> q;
        q.push({x, y});
        while(!q.empty()){
            auto cur = q.front();
            grid[cur.first][cur.second] = 0;
            q.pop();
            for(int k=0;k<4;k++){
                int nx = cur.first + nxt[k][0];
                int ny = cur.second + nxt[k][1];
                if(nx >= 0 && ny >= 0 && nx < m && ny < n){
                    if(grid[nx][ny]){
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;
        m = grid.size();
        n = grid[0].size();
        for(int i=0;i<m;i++){
            if(grid[i][0])
            bfs(grid, i, 0);
            if(grid[i][n-1])
            bfs(grid, i, n-1);
        }
        for(int j=0;j<n;j++){
            if(grid[0][j])
            bfs(grid, 0, j);
            if(grid[m-1][j])
            bfs(grid, m-1, j);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]) ans++;
            }
        }
        return ans;
    }
};