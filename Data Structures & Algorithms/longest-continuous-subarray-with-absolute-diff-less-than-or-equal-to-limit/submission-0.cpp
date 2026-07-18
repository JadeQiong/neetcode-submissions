class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0;
        int l = 0, r = 0;
        int n = nums.size();
        deque<int> minq, maxq;
        while(r<n){
            while(!minq.empty() && nums[r]<minq.back()){
                minq.pop_back();
            }
            while(!maxq.empty() && nums[r]>maxq.back()){
                maxq.pop_back();
            }
            minq.push_back(nums[r]);
            maxq.push_back(nums[r]);
            while(maxq.front() - minq.front() > limit){
                if(nums[l] == maxq.front()){
                    maxq.pop_front();
                }
                if(nums[l] == minq.front()){
                    minq.pop_front();
                }
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};