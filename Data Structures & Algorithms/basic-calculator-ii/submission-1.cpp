class Solution {
public:
    int calculate(string s) {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        stack<int> stk;
        int num = 0;
        char op = '+';
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(isdigit(ch)){
                num = num * 10 + (ch-'0');
            } 
            if(!isdigit(ch) || i == s.size()-1){
                if(op == '+'){
                    stk.push(num);
                } else if(op == '-'){
                    stk.push(-num);
                } else if(op == '*'){
                    int prev = stk.top();
                     stk.pop();
                    stk.push(prev * num);
                } else {
                    int prev = stk.top();
                    stk.pop();
                    stk.push(prev/num);
                }
                op = ch;
                num = 0;
            }
        }
        int res = 0;
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};