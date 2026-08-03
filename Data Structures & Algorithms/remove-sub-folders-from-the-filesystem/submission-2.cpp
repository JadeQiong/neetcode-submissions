class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folders) {
        vector<string> ans;
        sort(folders.begin(), folders.end());
        for(int i=0;i<folders.size();i++){
            if(i == 0) ans.push_back(folders[i]);
            else if(folders[i].find(ans.back() + "/") != 0){
                ans.push_back(folders[i]);
            }
        }
        return ans;
    }
};