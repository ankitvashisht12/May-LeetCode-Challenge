class Solution {
public:
    int findComplement(int num) {
        
        if(num == 0) return 1;
     
        int digits = (log(num)/log(2))+1;
        int mask = (unsigned)(1<<digits) - 1;
        int ans = num ^ mask;   

        
        return ans;
    }
};
