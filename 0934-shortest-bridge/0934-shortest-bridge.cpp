class Solution {
public:
    int bfs(vector<vector<int>> &grid,queue<pair<int,int>> &q,vector<vector<bool>> &vis){
        
        int count=0;
        int v=grid.size();
        q.push({101,101});
        
        while(q.size()>1){
          
            pair<int,int> point=q.front();
            
            
            if(point.first==101){
                q.pop();
                
                count++;
                q.push({101,101});
                
            }else{
                q.pop();
            
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if((abs(i)+abs(j))==1){
                        int px=point.first+i;
                        int py=point.second+j;
                         
                        if(px>=0 && py>=0 && px<v && py<v && vis[px][py]==false){
                            
                            if(grid[px][py]==1){
                                return count;
                            }
                            vis[px][py]=true;
                            q.push({px,py});
                          
                        }
                    }
                }
            }
            }
            
        }
        return INT_MAX;
    }
    void bfsVis(vector<vector<int>> &grid,vector<vector<bool>> &vis,int sourceX,int sourceY, queue<pair<int,int>> &req){
        
        int v=grid.size();
       
       
       queue<pair<int,int>> q;
        q.push({sourceX,sourceY});
        vis[sourceX][sourceY]=true;
        
        while(q.empty()==false){
           
            pair<int,int> point=q.front();
            q.pop();
            req.push(point);
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if((abs(i)+abs(j))==1){
                        int px=point.first+i;
                        int py=point.second+j;
                         
                        if(px>=0 && py>=0 && px<v && py<v && vis[px][py]==false&&grid[px][py]==1){
                           
                            vis[px][py]=true;
                            q.push({px,py});
                            
                        }
                    }
                }
            }
            
        }
        
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int res=INT_MAX;
        int v=grid.size();
        vector<vector<bool>> vis(v,vector<bool> (v,false));
        queue<pair<int,int>> q;
        bool flag=false;
        for(int i=0;i<grid.size();i++){
            int j;
            
            for( j=0;j<grid[0].size();j++){
                
                if(grid[i][j]==1){
                    
                bfsVis(grid,vis,i,j,q);
                    flag=true;
                   break;
                    }
            }
            if(flag){
                break;
            }
            }
      
        return bfs(grid,q,vis);
         
    }
   
};