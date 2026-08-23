class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<string> res;
        unordered_set<char> left;
        vector<int> right(26, 0);
        for(char c:s){
            right[c-'a']++;
        }
        for(int i=0;i<s.size();i++){
            right[s[i]-'a']--;
            for(int j=0;j<26;j++){
                if(left.count(j+'a') && right[j] > 0){
                    res.insert(string() + s[i] + char('a' + j));
                }
            }
            left.insert(s[i]);
        }
        return res.size();
    }
};