class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        int res = 0;
        vector<int> prevHeights(COLS);

        for (int r = 0; r < ROWS; r++) {
            vector<int> heights = matrix[r];
            vector<int> sortedHgts = matrix[r];

            for (int c = 0; c < COLS; c++) {
                if (heights[c] > 0) {
                    heights[c] += prevHeights[c];
                    sortedHgts[c] = heights[c];
                }
            }

            sort(sortedHgts.begin(), sortedHgts.end(), greater<int>());
            for (int i = 0; i < COLS; i++) {
                res = max(res, (i + 1) * sortedHgts[i]);
            }

            prevHeights = heights;
        }
        return res;
    }
};