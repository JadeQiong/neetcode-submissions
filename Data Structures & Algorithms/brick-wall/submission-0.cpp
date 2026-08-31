class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        // 1 2 2 1
        // 3 1 2
        // 1 3 2
        // 2 4
        // 3 1 2
        // 1 3 1 1
        map<int, int> cnt;
        for(int i=0;i<wall.size();i++){
            int x = 0;
            for(auto width: wall[i]){
                x += width;
                cnt[x]++;
            }
            cnt[x]--;
        }
        int maxCnt = 0;
        for(auto [k, v]:cnt){
            if(v > maxCnt){
              //  cout << k << " " << v << endl;
                maxCnt = v;
            }
        }
        cout << maxCnt << endl;
         return wall.size() - maxCnt;
    }
};