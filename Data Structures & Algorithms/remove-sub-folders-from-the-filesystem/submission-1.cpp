class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folders) {
        vector<string> ans;
        set<string> se(folders.begin(), folders.end());
        for(string& f:folders){
            ans.push_back(f);
            for(int i=0;i<f.size();i++){
                if(f[i] == '/' && se.count(f.substr(0, i))){
                    ans.pop_back();
                    break;
                }
            }
        }
        return ans;
    }
};