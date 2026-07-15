/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> st;
        vector<int> ed;
        for(auto interval: intervals){
            st.push_back(interval.start);
            ed.push_back(interval.end);
        }
        sort(st.begin(), st.end());
        sort(ed.begin(), ed.end());
        int l = 0, r = 0;
        int count = 0, ans = 0;
        while(l < st.size() && r < st.size()){
            if(st[l]<ed[r]){
                count++;
                l++;
            } else if(st[l] >= ed[r]){
                count--;
                r++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};
