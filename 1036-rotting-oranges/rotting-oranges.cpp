class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int count=0;
         for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==0){
                    count++;
                }
            }
        }
        if(count==rows*cols){
            return 0;
        }
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int directions[4][2]={
            {-1,0},
            {0,-1},
            {1,0},
            {0,1}
        };
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    visited[i][j]=true;
                }
            }
        }
        int mins=0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto curr=q.front();
                q.pop();
                int row=curr.first;
                int col=curr.second;
                for(auto& direction:directions){
                    int newrow=row+direction[0];
                    int newcol=col+direction[1];
                    if(newrow>=0&&newrow<rows&&newcol>=0&&newcol<cols&&grid[newrow][newcol]!=0){
                        if(!visited[newrow][newcol]){
                            q.push({newrow,newcol});
                            grid[newrow][newcol]=2;
                            visited[newrow][newcol]=true;
                        }
                    }
                } 
            }
            mins++;
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return mins-1;  
    }
};