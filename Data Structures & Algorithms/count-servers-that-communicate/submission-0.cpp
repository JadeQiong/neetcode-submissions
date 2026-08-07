class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) {
                    cnt++;
                }
            }
            if(cnt>1){
                for(int j=0;j<n;j++){
                    if(grid[i][j]){
                        grid[i][j]++;
                    }
                }
            }
        }
        for(int j=0;j<n;j++){
            int cnt = 0;
            for(int i=0;i<m;i++){
                if(grid[i][j]){
                    cnt++;
                }
            }
            if(cnt>1){
                for(int i=0;i<m;i++){
                    grid[i][j]++;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>1) ans++;
            }
        }
        return ans;
    }
};