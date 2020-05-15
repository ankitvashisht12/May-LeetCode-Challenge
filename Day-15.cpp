class Solution {
public:
    
    int maxSubarraySumCircular(vector<int>& A) {
        int n  = A.size();
        int curMax = A[0], ovMax = A[0];
        int curMin = A[0], ovMin = A[0];
        int total = A[0], _maxVal = A[0];
        
        if(n == 1) return A[0];
      
        for(int i =1; i< n; i++){
            total += A[i];
            _maxVal = max(_maxVal, A[i]);
            curMax = max(curMax + A[i], A[i]);
            ovMax = max(ovMax, curMax);
          
            curMin = min(curMin + A[i], A[i]);
            ovMin = min(ovMin, curMin);
        }
        
        
        if(ovMax <= 0) return _maxVal;
        
        return max({ovMax, (total - ovMin)});
    }
};
