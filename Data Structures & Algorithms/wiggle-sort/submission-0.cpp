class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        priority_queue<int> q;
        int n = nums.size();
        for(auto num:nums){
            q.push(num);
        }
        for(int i=1;i<n;i+=2){
            nums[i]=q.top();
            q.pop();
        }
        for(int i=0;i<n;i+=2){
            nums[i]=q.top();
            q.pop();
        }
    }
};
