class Solution {
public:
    int majorityElement(vector<int>& nums) {
    
        int vote = 1;
        int majority_ele = nums[0];
        for(int i = 1; i<nums.size(); i++){
            int n = nums[i];
            
            if(vote == 0) majority_ele = n, vote = 1;
            else if(majority_ele == n) vote++;
            else vote--;
        }
        
        return majority_ele;
    }
};
