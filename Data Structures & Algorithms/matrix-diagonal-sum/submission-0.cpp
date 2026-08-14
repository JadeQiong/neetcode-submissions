class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int n = mat.size();
        for(int i=0;i<n;i++){
            sum += mat[i][i];
        }
        for(int i=n-1;i>=0;i--){
            sum += mat[n-i-1][i];
        }
        if(n&1) sum -= mat[n/2][n/2];
        return sum;
    }
};