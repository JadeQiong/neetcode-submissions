class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int fi = 0, se = 0;
        for(auto price:prices){
            if(fi == 0){
                fi = price;
            }
            else if(se == 0){
                se = price;
                if(se < fi){
                    swap(se, fi);
                }
            }
            else if(price <= se){
                se = price;
                if(se <= fi){
                    swap(se, fi);
                }
               // cout << " fi = " << fi << ", se = " << se << endl;
            }
        }
        if(fi + se <= money) return money - fi - se;
        return money;
    }
};