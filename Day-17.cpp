class Solution {
public:
    
    bool checkAllZeros(int *hashmap){
        for(int i =0; i<26; i++)
            if(hashmap[i] != 0) return false;
        
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        int n = p.size();
        vector<int> result;
        if (s.size() == 0) return result; 
        int hashmap[26] = {0};
        
        for(auto ch : p){
            hashmap[ch - 'a'] += 1;
        }
        
        for(int i = 0;  i < s.size(); i++){
            char ch = s[i];
            hashmap[ch - 'a'] -= 1;
            
            if(i >= n)
                hashmap[s[i-n] - 'a'] += 1;
            
            if(i >= n -1 and checkAllZeros(hashmap)) result.push_back(i-n+1);
        }
        
        return result;
    }
};
