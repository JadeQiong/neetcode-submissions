class Solution {
public:
    string removeDuplicates(string s, int k) {
      string ans = "";
      stack<char> stk;
      int n = s.length();
      for(int i=0;i<n;i++){
        stk.push(s[i]);
        if(stk.size() >= k){
            char target = stk.top(); stk.pop();
            vector<char> pending;
            pending.push_back(target);
            bool ok = true;
            for(int j=0;j<k-1;j++){
                char cur = stk.top();
                stk.pop();
                pending.push_back(cur);
                if(cur != target){
                    ok = false;
                    break;
                }
            }
            if(!ok){
                for(int j=pending.size()-1;j>=0;j--){
                    stk.push(pending[j]);
                }
            }
        }
      }
      while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
      }
      reverse(ans.begin(), ans.end());
      return ans; 
    }
};