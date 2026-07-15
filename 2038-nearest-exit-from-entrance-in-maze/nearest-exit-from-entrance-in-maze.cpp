class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows=maze.size();
        int cols=maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        int directions[4][2]={
            {-1,0},
            {0,-1},
            {1,0},
            {0,1}
        };
        int steps=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto curr=q.front();
                q.pop();
                int row=curr.first;
                int col=curr.second;
                for(auto& direction:directions){
                    int newrow = row + direction[0];
                    int newcol = col + direction[1];
                    if(newrow<0||newrow>=rows||newcol<0||newcol>=cols){
                        continue;
                    }
                    if(maze[newrow][newcol]=='+'){
                        continue;
                    }
                    if(newrow==0||newrow==rows-1||newcol==0||newcol==cols-1){
                        return steps+1;
                    }
                    maze[newrow][newcol]='+';
                    q.push({newrow,newcol});
                }
            }
            steps++;
        }
        return -1;
    }
};