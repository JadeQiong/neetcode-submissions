class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        set<char> vowels;
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');

        vector<int> ans;
        int n = words.size();
        vector<int> pre(n+1);
        for(int i=0;i<n;i++){
            string str = words[i];
            if(vowels.count(str[0]) && vowels.count(str.back())){
                pre[i]=1;
            } else {
                pre[i]=0;
            }
        }

        for(int i=1;i<n;i++){
            pre[i] += pre[i-1];
        }

        for(int i=0;i<queries.size();i++){
            if(queries[i][0] == 0){
                ans.push_back(pre[queries[i][1]]);
            } else 
                ans.push_back(pre[queries[i][1]]-pre[queries[i][0]-1]);
        }
        
        return ans;
    }
};