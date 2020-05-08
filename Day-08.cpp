class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        
        if(n == 2) return true;
        
        
        int y1 = coordinates[1][1];
        int x1 = coordinates[1][0];
        int y0 = coordinates[0][1];
        int x0 = coordinates[0][0];
        double m, c;
        if(x1 - x0 == 0) m = 0;
        else m = (y1 - y0) / (x1 - x0);
         c = y0 - (m * x0);
        
        for(int i =2; i< n; i++){
            y1 = coordinates[i][1];
            x1 = coordinates[i][0];
            y0 = coordinates[i-1][1];
            x0 = coordinates[i-1][0];
            
            double new_m, new_c;
            
            if(x1 - x0 == 0) new_m = 0;
            else new_m = ((y1 - y0) / (x1 - x0));
            
            new_c = (y0 - (m * x0));
            
            if(m != new_m  || c != new_c)
                return false;
        }
        
        return true;
    }
};
