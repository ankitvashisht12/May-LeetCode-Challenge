class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        
        
        map<int, vector<int>> _map;
        for(auto _pair : dislikes){
            _map[_pair[0]].push_back(_pair[1]);
            _map[_pair[1]].push_back(_pair[0]);
        }
        
            
        vector<int> groups(N+1), visited(N+1, 0);
        stack<int> st;
        int g = 0;

        for(int i=1; i<=N; i++){
            if(visited[i] == 0){
                st.push(i);
                while(!st.empty()){
                    int val = st.top();
                    st.pop();

                    if(visited[val] == 0){
                        visited[val] = 1;
                        groups[val] =  g;
                    }

                    if(_map.find(val) != _map.end())
                        for(auto n : _map[val]){
                            if(visited[n] == 0) {
                                st.push(n);
                                (groups[val] == 1) ? groups[n] = 0 : groups[n] = 1;
                                visited[n] = 1;
                            }else{
                                if(groups[n] == groups[val]){
                                    return false;
                                }
                            }
                        }
                }
            }   
        }
        
        
        return true;
    }
};
