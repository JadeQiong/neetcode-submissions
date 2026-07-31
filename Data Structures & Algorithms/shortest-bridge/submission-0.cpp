class Solution {
public:
    int nxt[4][2]={{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int n;
    queue<pair<int, int>> q;
    void dfs(vector<vector<int>>& grid, int x, int y){
        grid[x][y]=2;
        q.push({x, y});
        for(int i=0;i<4;i++){
            int nx = x + nxt[i][0];
            int ny = y + nxt[i][1];
            if(nx >= 0 && ny >= 0 && nx < n && ny < n){
                if(grid[nx][ny] == 1){
                    
                    dfs(grid, nx, ny);
                }
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        bool found = false;
        for(int i=0;i<n;i++){
            if(found) break;
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(grid, i, j);
                    found = true;
                    break;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        int ans = 0;
        while(!q.empty()){
            int siz = q.size();
            while(siz){
                auto cur = q.front(); q.pop();
                for(int i=0;i<4;i++){
                    int nx = cur.first + nxt[i][0];
                    int ny = cur.second + nxt[i][1];
                    if(nx >= 0 && ny >= 0 && nx < n && ny < n){
                        if(grid[nx][ny] == 0){
                            grid[nx][ny]=2;
                            q.push({nx, ny});
                        } else if(grid[nx][ny] == 1){
                            return ans;
                        }
                    }
                }
                siz--;
            }
            ans++;
        }
        return ans;
    }
};