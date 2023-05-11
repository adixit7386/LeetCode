class Solution {
public:
    int dfs(vector<pair<int,int>> adj[],int src,vector<bool> &vis){
        vis[src]=true;
        int ans=INT_MIN;
        for(auto el:adj[src]){
            int k=el.second;
            if(vis[el.first]==false){
                
                k=k+dfs(adj,el.first,vis);
            }
            ans=max(ans,k);
            
        }
        if(ans==INT_MIN)
            return 0;
        return ans;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<n;i++){
            if(manager[i]!=-1)
            adj[manager[i]].push_back({i,informTime[manager[i]]});
        }
        vector<bool> vis(n,false);
        return dfs(adj,headID,vis);
    }
};