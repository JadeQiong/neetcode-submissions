class Solution {
public:
    vector<int> prefix;
    Solution(vector<int>& w) {
        int n = w.size();
        prefix.resize(n);
        for(int i=0;i<n;i++){
            if(i)
            prefix[i] = prefix[i-1] + w[i];
            else
            prefix[i] = w[i];
        }
    }
    
    int pickIndex() {
        int n = prefix.size();
        double target = prefix[n-1] * ( (double)rand()/RAND_MAX);
        int l = 0, r = n-1;
        while(l < r) {
            int mid = (l+r)>>1;
            if(prefix[mid] <= target){
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */