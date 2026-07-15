class Solution {
public:
    int compress(vector<char>& chars) {
        char cur = ' ';
        int cnt = 0;
        string ans = "";
        for(int i=0;i<chars.size();i++){
            if(cur == ' '){
                cur = chars[i];
                cnt++;
            } else if(cur != chars[i]){
                ans.push_back(cur);
                if(cnt != 1)
                    ans += to_string(cnt);
                cur = chars[i];
                cnt=1;
            } else {
                cnt++;
            }
        }
        ans.push_back(cur);
        if(cnt != 1)
            ans += to_string(cnt);
        cout << ans << endl;
        for(int i=0;i<ans.size();i++){
            chars[i] = ans[i];
        }
        return ans.size();
    }
};