class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans; 
        
        int i =0, j = 0;
        int len_A = A.size(), len_B = B.size();
        
        while(i < len_A and j < len_B){
            auto a = A[i];
            auto b = B[j];
            if((a[0] <= b[0] and a[1] >= b[0]) || (a[0] >= b[0] and a[0] <= b[1])){
                vector<int> temp;
                if(a[0] <= b[0]){
                    if(a[1] <= b[1]){
                        temp.push_back(b[0]);
                        temp.push_back(a[1]);
                        i++;
                    }else{
                        temp.push_back(b[0]);
                        temp.push_back(b[1]);
                        j++;
                    }
                }else{
                    if(a[1] >= b[1]){
                        temp.push_back(a[0]);
                        temp.push_back(b[1]);
                        j++;
                    }else{
                        temp.push_back(a[0]);
                        temp.push_back(a[1]);
                        i++;
                    }
                }
                ans.push_back(temp);
            }else{
                if(a[0] > b[1]) j++;
                else i++;
            }
        } 
        return ans;
    }
};
