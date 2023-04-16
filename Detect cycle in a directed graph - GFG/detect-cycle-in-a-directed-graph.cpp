//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int source,vector<bool>& vis,vector<int> adj[],vector<bool> &recSt){
        vis[source]=true;
        recSt[source]=true;
        for(auto ngb:adj[source]){
            if(vis[ngb]==false){
                if(dfs(ngb,vis,adj,recSt)==true){
                    return true;
                }
            }else if(recSt[ngb]==true){
                return true;
            }
        }
        recSt[source]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V,false);
        vector<bool> recSt(V,false);
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                if(dfs(i,vis,adj,recSt)==true){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends