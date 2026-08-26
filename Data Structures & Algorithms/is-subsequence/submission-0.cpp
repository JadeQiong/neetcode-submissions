class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p = 0;
        int i = 0;
        while(i < t.size() && p < s.size()){
            if(s[p] == t[i]){
                p++;
            }
            i++;
        }
        return p == s.size();
    }
};