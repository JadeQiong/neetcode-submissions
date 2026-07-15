class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       int n = fruits.size();
       int ans = 0;
       int l = 0, r = 0;
       int type1=-1, type2 = -1;
        int last1 = -1, last2 = -1;
        while(r<n){
            if(last1 == -1){
                last1 = r;
                type1=fruits[r];
            } else if(fruits[r] == type1){
                last1 = r;
            } else if(fruits[r] != type1
            && type2 == -1){
                type2=fruits[r];
                last2 = r;
            } else if(fruits[r] == type2){
                last2 = r;
            } else {
                if(last2 > last1){
                    l = last1+1;
                    type1=type2;
                    last1=last2;
                    type2=fruits[r];
                    last2=r;
                } else {
                    l = last2+1;
                    type2=fruits[r];
                    last2=r;
                }
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};