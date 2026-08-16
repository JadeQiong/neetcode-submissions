class Solution {
public:
    const int RIGHT=0, LEFT=1, UP=2, DOWN=3;
    const int nxt[4][2]={{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    const int nxt_dir[4] = {DOWN, UP, RIGHT, LEFT};
    void dfs(int num, int x, int y, int dir, vector<vector<int>>& ans, int n){
        if(num > n*n) return;
        ans[x][y]=num;
        if(num == n*n) return;
        int nx = x + nxt[dir][0];
        int ny = y + nxt[dir][1];
        if(nx >= 0 && ny >= 0 && nx < n && ny < n && ans[nx][ny] == 0){
            dfs(num+1, nx, ny, dir, ans, n);
        } else { 
            // out of bound, change dir
            dir = nxt_dir[dir];
            nx = x + nxt[dir][0];
            ny = y + nxt[dir][1];
            if(nx >= 0 && ny >=0 && nx < n && ny < n && ans[nx][ny] == 0)
            dfs(num+1, nx, ny, dir, ans, n);
            else {
                cout << "? " << nx << ", " << ny << " is not legal, dir " << dir << endl;
            }
        }
        return;
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        dfs(1, 0, 0, RIGHT, ans, n);
        return ans;
    }
};