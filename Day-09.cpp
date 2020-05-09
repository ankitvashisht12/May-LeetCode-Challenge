class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if (num == 1) return true;
        bool ans;
        int l = 1, h = num/2;
        long long int mid;
        while(l <= h){
            mid = l + ((h-l)/2);
            long long int sq = mid*mid;
            if(mid*mid == num) return true;
            else if(mid*mid > num){
                h = mid-1;
            }else l = mid+1;
        }
        
        return false;
    }
};
