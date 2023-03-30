class Solution {
public:
    int getCount(vector<vector<int>>& grid,queue<pair<int,int>>& q,vector<vector<bool>> &vis){
        int n=grid.size();
        int m=grid[0].size();
       
        int count=0;
        while(q.size()>1){
            pair<int,int> pr=q.front();
            q.pop();
            // cout<<pr.first<<" "<<pr.second<<" ";
            if(pr.first==-1){
                count++;
                q.push({-1,-1});
            }
            
            
            
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(abs(abs(i)-abs(j))==1){
                        
                        int x=pr.first+i;
                        int y=pr.second+j;

                        if(x<n&&x>=0&&y>=0&&y<m&&vis[x][y]==false){
                            if(grid[x][y]==1){
                                return count;
                            }
                            vis[x][y]=true;
                            q.push({x,y});
                        }
                    }
                }
            }
            
        }
        return INT_MAX;
    }
    void bfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>> &vis,queue<pair<int,int>>& qreal){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        vis[i][j]=true;
        q.push({i,j});
        
        while(!q.empty()){
            pair<int,int> pr=q.front();
            q.pop();
            qreal.push(pr);
            
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(abs(abs(i)-abs(j))==1){
                        
                        int x=pr.first+i;
                        int y=pr.second+j;

                        if(x<n&&x>=0&&y>=0&&y<m&&vis[x][y]==false&&grid[x][y]==1){
                            vis[x][y]=true;
                            q.push({x,y});
                        }
                    }
                }
            }
            
        }
        
    }
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        int i,j;
        bool flag=false;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j]==1){
                    bfs(i,j,grid,vis,q);
                    flag=true;
                    break;
                    
                }
            }
            if(flag==true){
                break;
            }
        }
        q.push({-1,-1});
        
        return getCount(grid,q,vis);
        
    }
};