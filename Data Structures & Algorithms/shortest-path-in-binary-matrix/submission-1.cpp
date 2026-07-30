class Solution {
public:
    int nxt[8][2]={{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        queue<pair<int, int>> q;
        if(grid[0][0]) return -1;
        q.push({0, 0});
        grid[0][0]=-1;
        while(!q.empty()){
            int siz = q.size();
            ans++;
            while(siz){
                auto cur = q.front();q.pop();
                if(cur.first == n-1 && cur.second == n-1){
                    return ans;
                }
                for(int i=0;i<7;i++){
                    int nx = cur.first + nxt[i][0];
                    int ny = cur.second + nxt[i][1];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                        if(grid[nx][ny]==0){
                            q.push({nx, ny});
                            grid[nx][ny]=-1;
                        }
                    }
                }
                siz--;
            }
        }
        return -1;
    }
};