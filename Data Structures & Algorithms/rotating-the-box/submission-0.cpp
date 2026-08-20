class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int ROWS = boxGrid.size();
        int COLS = boxGrid[0].size();
        for(int r = 0; r < ROWS; r++){
            int i = COLS - 1;
            for(int c = COLS-1; c>=0; c--){
                if(boxGrid[r][c] == '#'){
                    swap(boxGrid[r][c], boxGrid[r][i]);
                    i--;
                } else if(boxGrid[r][c] == '*'){
                    i = c-1;
                }
            }
        }
        vector<vector<char>> ans(COLS, vector<char>(ROWS, ' '));
        for(int r = 0; r < ROWS; r++){
            for(int c=0;c<COLS;c++){
                ans[c][ROWS-r-1]=boxGrid[r][c];
            }
        }
        return ans;
    }
};