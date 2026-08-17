class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars;
        for(int i=0;i<n;i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());
        stack<double> stk;
        for(int i=0;i<n;i++){
            double t = (target - cars[i].first)/(1.0 * cars[i].second);
            while(!stk.empty() && stk.top() <= t){
                stk.pop();
            }
            stk.push(t);
        }
        return stk.size();
    }
};
