//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    // using dfs
    // bool dfs(vector<int> adj[],int src,vector<bool> &vis,int parent){
    //     vis[src]=true;
    //     for(auto ngb:adj[src]){
    //         if(vis[ngb]==false){
    //             if(dfs(adj,ngb,vis,src)==true){
    //                 return true;
    //             }
    //         }else if(ngb!=parent){
    //                 return true;
    //             }
    //     }
    //     return false;
    // }
    
    // using bfs
    bool dfs(vector<int> adj[],int src,int V,vector<bool> &vis){
        
        vector<int> par(V,-1);
        queue<int> q;
        q.push(src);
        vis[src]=true;
        par[src]=-1;
        while(q.empty()==false){
            int baap=q.front();
            q.pop();
            
            for(auto beta:adj[baap] ){
                if(vis[beta]==false){
                    q.push(beta);
                    vis[beta]=true;
                    par[beta]=baap;
                }else if(par[baap]!=beta){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                if(dfs(adj,i,V,vis)){
                    return true;
                    
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends