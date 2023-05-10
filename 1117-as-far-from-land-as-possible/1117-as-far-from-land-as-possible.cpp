class Solution {
public:
    int bfs(vector<vector<int>>& grid,queue<pair<int,int>> &q,vector<vector<bool>> &vis){
        int n=grid.size();
        int m=grid[0].size();
        int level=0;
        q.push({-1,-1});
        while(q.size()>1){
            pair<int,int> pr=q.front();
            q.pop();
            if(pr.first==-1){
                level++;
                q.push({-1,-1});
                continue;
            }
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(abs(i-j)==1){
                        int x=i+pr.first;
                        int y=j+pr.second;
                        // cout<<x<<" "<<y<<endl;
                        // cout<<vis[x][y]<<endl;
                        if(x>=0 && y>=0 && x<n && y<m && vis[x][y]==false ){
                            
                            // cout<<<<endl;
                            vis[x][y]=true;
                            q.push({x,y});
                            
                        }
                    }
                }
            }
        }
        return level;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        queue<pair<int,int>> q;
        bool flag=false;
        bool flag2=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    flag=true;
                    q.push({i,j});
                    vis[i][j]=true;
                }else{
                    flag2=true;
                }
            }
        }
        if(!flag)return-1;
        if(!flag2)return-1;
        return bfs(grid,q,vis);
    }
};