class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        map<int, int> mp;
        int n = x.size();
        for(int i=0;i<n;i++){
            if(mp.count(x[i])){
                mp[x[i]] = max(mp[x[i]],y[i]);
            } else{
                mp[x[i]]= y[i];
            }
            //cout << x[i] << endl;
            
        }
        if(mp.size() < 3) return -1;
        vector<int> ans;
        for(auto [k, v]: mp){
            //cout << " k = " << k << ", v = " << v << endl;
            ans.push_back(v);
        }
        sort(ans.begin(), ans.end());
        int m = ans.size();
        // for(int i=0;i<m;i++){
        //     cout << ans[i] << " ";
        // }
        return ans[m-1] + ans[m-2] + ans[m-3];
    }
};