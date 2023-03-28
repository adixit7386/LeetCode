class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int> (m,false));
        
        q.push({sr,sc});
        int checkx=grid[sr][sc];
        vis[sr][sc]=true;
        grid[sr][sc]=color;
        
        
        while(q.empty()==false){
            pair<int,int> currPt=q.front();
            q.pop();
            
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(abs(abs(i)-abs(j))==1){
                        int x=currPt.first+i;
                        int y=currPt.second+j;
                        // cout<<grid[x][y]<<" "<<checkx<<endl;
                        
                        if(x>=0&&x<n&&y>=0&&y<m&&grid[x][y]==checkx&&vis[x][y]==false){
                            grid[x][y]=color;
                            vis[x][y]=true;
                            // cout<<x<<y<<endl;
                            q.push({x,y});
                        }
                    }
                }
            }
            
          
        }
        return grid;
    }
};