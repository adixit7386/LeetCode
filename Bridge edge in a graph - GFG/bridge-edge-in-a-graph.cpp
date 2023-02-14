//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    void bridges(vector<int> adj[],int s,vector<bool> &vis,vector<int> &disc,vector<int> &low,int &time,int parent,int c,int d,bool &flag)
    {
        vis[s]=true;
        disc[s]=time;
        low[s]=time;
        time++;
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
                bridges(adj,u,vis,disc,low,time,s,c,d,flag);
                low[s]=min(low[s],low[u]);
                if(low[u]>disc[s]) 
	               {
	                   if(u==c&&s==d||u==d&&s==c)
	                   {
	                       flag=true;
	                   }
	               }
            }else{
                low[s]=min(low[s],disc[u]);
            }
        }
        
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        
        vector<bool> vis(V,false);
        vector<int> disc(V,-1);
        vector<int> low(V,-1);
        int time=0;
        bool flag=false;
        
        for(int i=0;i<V;i++){
           
            
            
            if(vis[i]==false){
                bridges(adj,i,vis,disc,low,time,-1,c,d,flag);
            }
        }
        
        return flag;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends