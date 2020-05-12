class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

//         log(n) solution
        
        int low = 0, high = nums.size()-1;
            
        if(high == 0) return nums[high];
        
        while(low < high){
            
            int mid = low + ((high- low) / 2);
            
            if(nums[mid] != nums[mid-1] and nums[mid] != nums[mid+1]){
                return nums[mid];
            }
            else if(mid % 2 == 0){
                if(nums[mid+1] == nums[mid]){
                    low = mid+2;
                }else high = mid - 2;
            }
            else{
                if(nums[mid+1] == nums[mid]){
                    high = mid - 1;
                }else low = mid + 1;
            }
        }
        
        return nums[low];
        
        
//         O(n) Solution

//         int ans = 0, i=0;
//         int n = nums.size();
//         if(n == 1) return nums[i];

//         for(; i<n-1; i+=2)
//             ans ^= nums[i]^nums[i+1];
        
//         ans ^= nums[n-1];
        
//         return ans;
        
        
    }
};
