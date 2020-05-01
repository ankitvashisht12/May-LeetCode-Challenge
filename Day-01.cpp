// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    
    int binSearch(int low , int high){
        while(low <= high){
            int mid = low + (high - low)/2;
            bool badVersion = isBadVersion(mid);
            
            if(!badVersion) low = mid+1;
            else high = mid-1;
        }
        
        return low;
    }
    
    int firstBadVersion(int n) {
        return binSearch(1, n);
    }
};
