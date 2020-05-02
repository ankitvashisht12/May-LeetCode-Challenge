class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int ans = 0;
        unordered_map<char, int> m;
        
        for(auto ch: S){
            m[ch]++;
        }
        
        for(auto ch: J){
            ans += m[ch];
        }
        
        return ans;
    }
};
