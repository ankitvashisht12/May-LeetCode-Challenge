class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0, i=0;
        int n = nums.size();
        if(n == 1) return nums[i];

        for(; i<n-1; i+=2)
            ans ^= nums[i]^nums[i+1];
        
        ans ^= nums[n-1];
        
        return ans;
    }
};
