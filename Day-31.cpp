class Solution {
public:
    int minDistance(string word1, string word2) {
        int p1 = word1.size();
        int p2 = word2.size();
        
        vector<vector<int>> cache(p2+1, vector<int>(p1+1, 0));
        for(int i=0; i<p1+1; i++) cache[0][i] = i;
        for(int i=0; i<p2+1; i++) cache[i][0] = i;

        for(int i =1; i<p2+1; i++)
            for(int j = 1; j<p1+1; j++){
                if(word1[j-1] != word2[i-1])
                cache[i][j] = min({cache[i-1][j-1], cache[i-1][j], cache[i][j-1]}) + 1;
                else cache[i][j] = cache[i-1][j-1];
            }
        
        return cache[p2][p1];
    }
};
