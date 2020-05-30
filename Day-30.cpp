class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        set<pair<int, pair<int, int>>> s;
        for(auto p : points){
            int sum_sq = pow(p[0], 2)+pow(p[1], 2);
            s.emplace(sum_sq, make_pair(p[0], p[1]));
        }
     
        vector<vector<int>> ans;
        
        for(auto i : s){
            if(k==0) break;
            else{
                vector<int> temp;
                auto p = i.second;
                temp.push_back(p.first);
                temp.push_back(p.second);
                ans.push_back(temp);
                --k;
            }
        }
        
        return ans;
    }
};
