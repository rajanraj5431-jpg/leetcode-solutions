class Solution {
public:
    void dfs(int room, const vector<vector<int>>& rooms, vector<bool>& visited){
        visited[room]=true;
        for(int i=0;i<rooms[room].size();i++){
            if(!visited[rooms[room][i]]){
                dfs(rooms[room][i],rooms,visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(),false);
        dfs(0,rooms,visited);
        for(int i=0;i<visited.size();i++){
            if(visited[i]==false){
                return false;
            }
        }
        return true;
    }
};