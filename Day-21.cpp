class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int ans = 0; 
        vector<int> top_row(cols);
        int top_left = 0; 
        for(int i =0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(matrix[i][j] == 1)
                   if(i ==0) top_row[j] = matrix[i][j];
                   else{
                       if(j == 0) top_row[j] = matrix[i][j], top_left = matrix[i-1][j];
                       else{
                            int left = top_row[j-1];
                            int top = top_row[j];
                            top_row[j] = 1 + min({left, top, top_left}); 
                            top_left = top;
                       }
                   
                   }  
                else top_row[j] = 0;
                ans += top_row[j];             
            }
        }
        return ans;
    }
};
