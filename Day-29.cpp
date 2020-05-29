class Solution {
public:
    
    bool dfs(map<int, vector<int>>& adjMat, vector<int>& visited, int p){
        
        if(visited[p] == 1) return false;
        visited[p] = 1;
        for(auto n : adjMat[p])
            if(!dfs(adjMat, visited, n)) return false;
        visited[p] = 2;
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses);
        map<int, vector<int>> adjMat;
      
        for(auto n : prerequisites){
            adjMat[n[0]].push_back(n[1]);
        }
        
        for(int i =0; i<numCourses; i++){
            if(visited[i] == 0 and !dfs(adjMat, visited, i)) return false;
        }
        
        return true;
    }
};
