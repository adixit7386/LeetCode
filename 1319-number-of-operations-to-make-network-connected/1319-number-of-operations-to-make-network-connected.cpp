class Solution {
public:
    void dfs(int s,vector<bool> &vis,vector<int> adj[]){
        vis[s]=true;
        
        for(auto u:adj[s]){
            if(vis[u]==false){
                dfs(u,vis,adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        int edges=connections.size();
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            
        }
        
        vector<bool> vis(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                count++;
                dfs(i,vis,adj);
            }
        }
        if(edges<n-1){
            return -1;
        }
        return count-1;
    }
};