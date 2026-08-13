class Solution {
public:
    map<int, vector<int>> mp;
    void dfs(string &s, int index, int x, int y, int dir, vector<vector<char>>& v, int numRows){
        if(index >= s.length()) return;
        v[x][y]=s[index];
        if(dir == 0){
            if(x == numRows-1){
                dfs(s, index+1, x-1, y+1, 1, v, numRows);
            } else {
                dfs(s, index+1, x+1, y, 0, v, numRows);
            }
        } else {
            if(x == 0){
                dfs(s, index+1, x+1, y, 0, v, numRows);
            } else {
                dfs(s, index+1, x-1, y+1, 1, v, numRows);
            }
        }
    }
    // 3*n-2 -> n
    string convert(string s, int numRows) {
        int n = s.length();
        int numCols = (n+3*numRows-1)/(3*numRows-2)*n;
        vector<vector<char>> v(numRows, vector<char>(numCols, ' '));
        // down
        mp[0]={1, 0};
        // up right
        mp[1]={-1, 1};
        dfs(s, 0, 0, 0, 0, v, numRows);
        string ans;
        for(int i=0;i<numRows;i++){
            for(int j=0;j<numCols;j++){
                if(v[i][j]!=' '){
                    ans.push_back(v[i][j]);
                }
            }
        }
        return ans;
    }
};