class Solution {
public:
    vector<string> ans;
    void dfs(int i, string s, int cnt, string& cur){
        if(i > s.length()) return;
        if(cnt == 4 && i == s.length()){
            ans.push_back(cur);
            return;
        }
        if(s[i] == '0'){
            // only allow single '0' segment
            string nxt = cur + "0";
            if(cnt + 1 < 4) nxt += ".";
            dfs(i+1, s, cnt+1, nxt);
            return;  // don't allow "00", "01", etc.
        }

        string str_num = "";
        for(int j = i; j <= i+2 && j < s.length(); j++){
            str_num.push_back(s[j]);
            int num = stoi(str_num);
            if(num > 255) break;        // ✅ break not return
            
            string nxt = cur + str_num; // ✅ rebuild nxt fresh each time
            if(cnt < 3) nxt += ".";
            dfs(j+1, s, cnt+1, nxt);
            // no need to pop since nxt is local now
        }
    }
    vector<string> restoreIpAddresses(string s) {
        for(auto c:s){
            if(!(c>='0' && c<='9') && !(c == '.')){
                return ans;
            }
        }
        string cur = "";
        dfs(0, s, 0, cur);
        return ans;
    }
};