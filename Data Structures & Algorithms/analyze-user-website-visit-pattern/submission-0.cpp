class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
     int n = timestamp.size();
     vector<pair<int, int>> arr;
     for(int i=0;i<n;i++){
        arr.push_back({timestamp[i], i});
     }   
     sort(arr.begin(), arr.end(), [](auto &a, auto& b){
        return a.first < b.first;
     });
     unordered_map<string, vector<string>> mp;
     for(auto &p: arr){
        mp[username[p.second]].push_back(website[p.second]);
     }

     unordered_map<string,int> count;
     for(auto& kv: mp){
        auto & website_list = kv.second;
        unordered_set<string> patterns;
        for(int i=0;i<website_list.size();i++){
            for(int j=i+1;j<website_list.size();j++){
                for(int k=j+1;k<website_list.size(); k++){
                    patterns.insert(website_list[i]  +"#"+website_list[j] + "#" + website_list[k]);
                }
            }
        }
        for(auto p:patterns){
            count[p]++;
        }
     }
     int maxCnt = 0;
     string res = "";
     for(auto& kv: count){
        if(kv.second > maxCnt){
            maxCnt = kv.second;
            res = kv.first;
        } else if(kv.second == maxCnt){
            if(kv.first < res){
                res = kv.first;
            }
        }
     }

     vector<string> ans;
     string tmp;
     for(auto ch:res){
        if(ch == '#'){
            ans.push_back(tmp);
            tmp = "";
        } else {
            tmp.push_back(ch);
        }
     }
     ans.push_back(tmp);
     return ans;
    }
};