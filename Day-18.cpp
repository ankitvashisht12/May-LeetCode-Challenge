class Solution {
public:
    
    void printHashMap(int *hashmap){
        for(int i = 0; i<26; i++)
            cout<<hashmap[i]<<" ,";
        cout<<endl;
    }
    
    bool checkAllZeros(int *hashmap){
        for(int i=0; i<26; i++)
            if(hashmap[i] != 0) return false;
        
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        
        if(n2 < n1) return false;
        
        int hashmap[26] = {0};
        for(auto ch : s1){
            hashmap[ch-'a'] += 1;
        }
        
        for(int i=0; i<n2; i++){
            hashmap[s2[i] - 'a']  -= 1;
            
            if(i >= n1){
                // cout<<i<<" "<<s2[i-n2]<<" ";
                // printHashMap(hashmap);
                hashmap[s2[i-n1] -'a'] += 1;
            }
            
            if(i >= n1-1 and checkAllZeros(hashmap)){
                return true;
            }
        }
        
        return false;
    }
};
