class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        map<int, int> m;
        
        if(N == 1) return 1;
        for(auto i : trust){
            m[i[0]]--;
            m[i[1]]++;
        }
        
        for(auto p : m){
            if(p.second == N-1){
                return p.first;
            }
        }
        
        return -1;
    }
};
