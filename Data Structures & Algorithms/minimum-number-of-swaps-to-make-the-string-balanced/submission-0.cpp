class Solution {
public:
    int minSwaps(string s) {
        stack<char> stk;
        if(s.size() == 0) return 0;
        int rightCnt = 0;
        for(auto c:s){
            if(c == '['){
                stk.push(c);
            } else {
                if(stk.size()) {
                    stk.pop();
                }
            }
        }
        return (stk.size()+1)/2;
    }
};