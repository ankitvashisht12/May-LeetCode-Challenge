class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();

        unordered_map<char, int> _map;
        for(auto ch : s){
            _map[ch]++;
        }
        
        vector<list<char>> bucket(n+1);
        
        for(auto p : _map){
            bucket[p.second].push_back(p.first);
        }
        
        string ans = "";
        for(int i = n; i>=0; i--){
               list<char> head = bucket[i];
               while(!head.empty()){
                    char ch = head.front();
                    head.pop_front();
                    int freq = _map[ch];
                    while(freq > 0) ans += ch, freq--; 
               }
        }
        return ans;
    }
};
