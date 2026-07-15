class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0;
        int j = 0;
        while(i<t.length()&&j<s.length()){
            if(t[i] == s[j]){
                i++;
                j++;
            } else {
                j++;
            }
        }
        if(i==0){
            return t.length();
        }
        if(i == t.length()) return 0;
        return t.length() - i;
    }
};