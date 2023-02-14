//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void bridges(vector<int> adj[],int s,vector<bool> &vis,vector<int> &disc,vector<int> &low,int &time,int parent,vector<int> &ans)
    {
        vis[s]=true;
        disc[s]=time;
        low[s]=time;
        time++;
        int childCount=0;
        for(auto u:adj[s]){
            // if(vis[u]==false){
            //     bridges(adj,u,vis,disc,low,time,s);
            //     low[s]=min(low[s],low[u]);
            // }else if(u!=parent){
            //     low[s]=min(low[s],low[u]);
            // }
            if(u==parent){
                continue;
            }
             if(vis[u]==false){
                bridges(adj,u,vis,disc,low,time,s,ans);
                low[s]=min(low[s],low[u]);
                
                if(low[u]>=disc[s]&&parent!=-1) 
	               {
	                   ans[s]=1;
	               }
	               childCount++;
            }else{
                low[s]=min(low[s],disc[u]);
            }
            
        }
        if(childCount>1&&parent==-1){
            ans[s]=1;
        }
        
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> ans(V,0);
        vector<bool> vis(V,false);
        vector<int> disc(V,-1);
        vector<int> low(V,-1);
        
        int time=0;
        
        
        for(int i=0;i<V;i++){
           
            
            
            if(vis[i]==false){
                bridges(adj,i,vis,disc,low,time,-1,ans);
            }
        }
        vector<int> returns;
        for(int i=0;i<V;i++){
            if(ans[i]){
                returns.push_back(i);
            }
        }
        if(returns.size()==0){
            returns.push_back(-1);
        }
        return returns;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends