class Solution {
public:
    
    
    void floodfill(vector<vector<int>>& image, vector<vector<int>>& visited, int oC, int nC, int r, int c, int n_rows, int n_cols){
        if(r < 0 || r >= n_rows || c < 0 || c >= n_cols) return ;
        
        if(image[r][c] == oC && visited[r][c] == 0){
            image[r][c] = nC;
            visited[r][c] = 1;
            
            floodfill(image, visited, oC, nC, r-1, c, n_rows, n_cols); // up
            floodfill(image, visited, oC, nC, r, c-1, n_rows, n_cols); // left
            floodfill(image, visited, oC, nC, r, c+1, n_rows, n_cols); // right
            floodfill(image, visited, oC, nC, r+1, c, n_rows, n_cols); // down
        }
            
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int n_rows = image.size();
        int n_cols = image[0].size();
        
        int oldColor = image[sr][sc];
        vector<vector<int>> visited (n_rows, vector<int>(n_cols, 0));
        
        floodfill(image, visited, oldColor, newColor, sr, sc, n_rows, n_cols);
        
        return image;
    }
};
