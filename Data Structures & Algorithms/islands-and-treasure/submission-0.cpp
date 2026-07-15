class Solution {
public:
    int nxt[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void BFS(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& vis){
        queue<pair<int, int>> q;
        queue<int> dis;
        q.push({x, y});
        dis.push(0);
        vis[x][y]=1;
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            auto cur_dis = dis.front();
            dis.pop();
            grid[cur.first][cur.second] = min(grid[cur.first][cur.second], cur_dis);
            for(int k=0;k<4;k++){
                int nx = cur.first + nxt[k][0];
                int ny = cur.second + nxt[k][1];
                if(nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size()){
                    if(!vis[nx][ny] && grid[nx][ny] != -1){
                        vis[nx][ny]=1;
                        q.push({nx, ny});
                        dis.push(cur_dis+1);
                    }
                }
            }
        }
        
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<vector<bool>> vis(n, vector<bool>(m, 0));
                if(grid[i][j] == 0){
                    BFS(grid, i, j, vis);
                }
            }
        }
    }
};
