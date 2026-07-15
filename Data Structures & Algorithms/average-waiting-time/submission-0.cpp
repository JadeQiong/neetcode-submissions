class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long total = 0;
        long long t = 0;
        for(int i=0;i<customers.size();i++){
            auto customer = customers[i];
            int start = customer[0];
            int duration = customer[1];
            if(start <= t){
                total += (t-start);
                t += duration;
            } else {
                t = start + duration;
            }
            total += duration;
            cout << i << "th customer, t = " << t << ", total = " << total << endl;
        }    
        return double(total/(1.0*customers.size())) ;
    }
};