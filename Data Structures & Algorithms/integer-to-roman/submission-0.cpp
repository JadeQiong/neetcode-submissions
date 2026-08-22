class Solution {
public:
    vector<pair<string, int>> symList = {
        {"I", 1}, 
        {"IV", 4}, {"V", 5},
        {"IX", 9}, {"X", 10}, 
        {"XL", 40}, {"L", 50},
        {"XC", 90}, {"C", 100},
        {"CD", 400}, {"D", 500},
        {"CM", 900}, {"M", 1000}
    };
    string intToRoman(int num) {
        string res = "";
        for(int i=symList.size()-1; i>=0 ;i --){
            string sym = symList[i].first;
            int val = symList[i].second;
            int count = num / val;
            if(count){
                res.append(count, sym[0]);
                if(sym.size()>1){
                    res.append(1, sym[1]);
                }
                num %= val;
            }

        }
        return res;
    }
};