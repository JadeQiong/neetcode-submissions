class Solution {
public:
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, bool> vis;
    string res;
    string foreignDictionary(vector<string>& words) {
        for(auto word: words){
            for(auto ch: word){
                adj[ch];
            }
        }
        for(int i=0;i<words.size()-1;i++){
            const string w1 = words[i];
            const string w2 = words[i+1];
            int len = min(w1.size(), w2.size());
            if(w1.length() > w2.length() && w1.substr(0, len) == w2.substr(0, len)){
                return "";
            }
            for(int j=0;j<len;j++){
                if(w1[j] != w2[j]){
                    adj[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }
        for(const auto& pair: adj){
            if(dfs(pair.first)){
                return "";
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool dfs(char ch){
        if(vis.find(ch) != vis.end()){
            return vis[ch];
        }
        vis[ch]=true;
        for(char nxt:adj[ch]){
            if(dfs(nxt)){
                return true;
            }
        }
        vis[ch]=false;
        res.push_back(ch);
        return false;
    }
};
