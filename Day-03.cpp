class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m1;
        
        for(auto ch : magazine){
            m1[ch]++;
        }
        
        for(auto ch : ransomNote){
            if(m1.find(ch) != m1.end()){
                if(m1[ch] < 0 ) return false;
                else m1[ch]--;
            }else return false;
        }
        
        
        for(auto ch : ransomNote){
            if(m1[ch] < 0) return false;
        }
        return true;
    }
};
