class Solution {
public:
    void dfs(int s,vector<bool> &vis,vector<int> adj[],vector<bool> &isSafe){
        vis[s]=true;
        bool flag=true;
        for(auto u:adj[s]){
            if(vis[u]==false){
                dfs(u,vis,adj,isSafe);
               
            }
            if(isSafe[u]==false){
                flag=false;
            }
             
            
        }
        if(flag){
            isSafe[s]=true;
        }
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& connections) {
        int n=connections.size();
        vector<int> adj[n];
        int edges=connections.size();
        vector<bool> isSafe(edges,false);
        for(int i=0;i<connections.size();i++){
            if(connections[i].size()==0){
                isSafe[i]=true;
            }else{
                for(auto k:connections[i]){
                    adj[i].push_back(k);
                    
                }
            
            
            }
            
        }
        
        vector<bool> vis(n,false);
       
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                
                dfs(i,vis,adj,isSafe);
            }
        }
        
        vector<int> ans;
        for(int i=0;i<isSafe.size();i++){
            
            if(isSafe[i]){
             
                ans.push_back(i);
            }
        }
        return ans;
    }
};