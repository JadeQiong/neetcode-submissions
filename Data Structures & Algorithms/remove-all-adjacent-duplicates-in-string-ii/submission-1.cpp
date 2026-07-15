class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> stk;
        for(auto c:s){
            if(!stk.empty() && stk.back().first == c){
                stk.back().second ++;
            } else {
                stk.push_back({c, 1});
            }
            if(stk.back().second == k){
                stk.pop_back();
            }
        }
        string res;
        for(auto& p: stk){
            res.append(p.second, p.first);
        }
        return res;
    }
};