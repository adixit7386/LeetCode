class Solution {
public:
    void bfs(vector<int> adj[],int src,vector<bool> &vis){
       vis[src]=true;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int el=q.front();
            q.pop();
            for(auto neighbour:adj[el]){
                if(vis[neighbour]==false){
                    vis[neighbour]=true;
                    q.push(neighbour);
                }
            }
        }
        
    }
    int makeConnected(int size, vector<vector<int>>& connections) {
        int edges=connections.size();
        vector<int> adj[size];
        
//         vector<vector<int>> grid(size,vector<int> (size,0));
        
        for(auto wire:connections){
            // grid[wire[0]][wire[1]]=true;
            adj[wire[0]].push_back(wire[1]);
            adj[wire[1]].push_back(wire[0]);
        }
        // int n=grid.size();
        // int m=grid[0].size();
        // vector<vector<bool>> vis(n,vector<bool> (m,false));
        
        vector<bool> vis(size,false);
        int i,j;
        int count=0;
        for(int i=0;i<size;i++){
            if(vis[i]==false){
                bfs(adj,i,vis);
                count++;
            }
        }
       if(edges<size-1){
           return -1;
       }
        return count-1;
        

    }
};