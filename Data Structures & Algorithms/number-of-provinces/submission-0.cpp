class Solution {
public:
    vector<int> f;
    int find(int x){
        return f[x] == x ? x : f[x]=find(f[x]);
    }
    void merge(int i, int j){
        int fi = find(i);
        int fj = find(j);
        if(fi != fj) f[fi] = fj;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        f.resize(n);
        for(int i=0;i<n;i++){
            f[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(isConnected[i][j]){
                    merge(i, j);
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(f[i] == i) cnt++;
        }
        return cnt;
    }
};