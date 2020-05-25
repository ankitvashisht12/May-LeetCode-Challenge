class Solution {
    vector<vector<int>> cache;
public:
    
    Solution():cache(502, vector<int>(502, 0)){}
    
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int na = A.size();
        int nb = B.size();
        
        for(int i =1 ; i <= na ; i++){
            for(int j = 1; j <= nb ; j++){
                if(A[i-1] == B[j-1])
                    cache[i][j] = 1 + cache[i-1][j-1];
                else cache[i][j] = max(cache[i][j-1], cache[i-1][j]);
            }
        }
        
        return cache[na][nb];
    }
};
