class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int pos = 1;
        int cnt = 1;
        int cur = nums[0];
        int i = 1;
        while(i<n){
            if(nums[i] == cur){
                cnt++;
                if(cnt <= 2){
                    // cout << " current count of " << cur << " is " << cnt << endl;
                    // cout << "pos = " << pos << endl;
                    nums[pos++] = cur;
                }
            } else {
                cnt = 1;
                cur = nums[i];
                nums[pos++] = cur;
            }
            i++;
        }
        // for(int j=0;j<min(cnt, 2);j++){
        //     nums[pos++]=cur;
        // }
        return pos;
    }
};