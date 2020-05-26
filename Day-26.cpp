class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        map<int, int> _map;
        _map[0] = -1;
        int maximum = 0;
        for(int i =0; i<nums.size(); i++){
            (nums[i] == 0)? sum += -1 : sum += 1;
            if(_map.find(sum) != _map.end()){
                maximum = max(i-_map[sum], maximum);
            }else
                _map[sum] = i;
        } 
        
        return maximum;
    }
};
