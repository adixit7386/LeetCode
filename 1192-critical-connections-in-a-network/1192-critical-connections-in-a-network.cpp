class Solution {
public:
    void dfs(vector<int> adj[],int source,int parent,vector<bool>& vis,vector<int> &mini,vector<int> &disc,int &count,vector<vector<int>> &ans){
        vis[source]=true;
        disc[source]=count;
        mini[source]=count;
        
        count++;
        for(auto ngb:adj[source]){
            if(vis[ngb]==false){
                dfs(adj,ngb,source,vis,mini,disc,count,ans);
                mini[source]=min(mini[source],mini[ngb]);
                if(mini[ngb]>disc[source]){
                    ans.push_back({source,ngb});
                }
            }else if(ngb!=parent){
                mini[source]=min(mini[source],disc[ngb]);
                if(mini[ngb]>disc[source]){
                    ans.push_back({source,ngb});
                }
            }
        }
        return;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        int src=-1;
        for(auto edge:connections){
            if(src==-1)src=edge[0];
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int count=0;
        vector<int> disc(n,0);
        vector<int> mini(n,0);
        vector<bool> vis(n,false);
        int parent=-1;
        vector<vector<int>> ans;
        dfs(adj,src,-1,vis,mini,disc,count,ans);
        for(int i=0;i<n;i++){
            cout<<disc[i]<<" "<<mini[i]<<endl;
        }
        return ans;
    }
};