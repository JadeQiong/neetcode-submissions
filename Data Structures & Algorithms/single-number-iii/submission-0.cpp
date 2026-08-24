class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int num = 0;
        for(auto i:nums){
            num ^= i;
        }
        int bit = num & (-num);
        int a = 0, b = 0;
        for(auto i:nums){
            if(bit & i){
                a ^= i;
            } else {
                b ^= i;
            }
        }
        return vector<int>{a, b};
    }
};