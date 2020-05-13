class Solution {
public:
    string removeKdigits(string num, int k) {
        int len = num.size();
        
        int i =0;
        if(len == k) return "0";
        
        while(k > 0){
            i = (i > 0) ? (i - 1): 0;
            while(num[i] <= num[i+1] && i < len-1)
                i++;
            num.erase(num.begin() + i);
            k--;
        }
        
        // handling leading zeros 
        
        // if(num[0] == '0'){
        //     int number = stoi(num);
        //     num = to_string(number);
        // }
        
        auto pos = num.find_first_not_of("0");
        num.erase(0, pos);
        
        if(num.size() == 0) return "0";
        
        return num;
    }
};
