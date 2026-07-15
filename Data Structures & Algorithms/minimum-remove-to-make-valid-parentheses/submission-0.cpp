class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        int n = s.length();
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i]!='(' && s[i] !=')'){
                ans.push_back(s[i]);
            } else if(s[i] == '('){
                cnt++;
                ans.push_back(s[i]);
            } else if(s[i] == ')') {
                if(cnt) {
                    cnt--;
                    ans.push_back(s[i]);
                }
            }
        }
        cout << ans << endl;
        string res;
        if(cnt > 0){
            // delete cnt last ) from ans
            for(int i=ans.length()-1;i>=0;i--){
                if(ans[i] == '(' && cnt > 0){
                    cnt--;
                } else {
                    res.push_back(ans[i]);
                }
            }
        } else {
            return ans;
        }
        reverse(res.begin(), res.end());
        return res;    
    }
};
