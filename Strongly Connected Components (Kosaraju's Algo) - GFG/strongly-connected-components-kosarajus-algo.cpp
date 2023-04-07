//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfsStack(int source,vector<vector<int>>& adj,vector<bool> &vis,stack<int> &st){
	    vis[source]=true;
	    for(int neighbour:adj[source]){
	        if(vis[neighbour]==false){
	            dfsStack(neighbour,adj,vis,st);
	        }
	    }
	    st.push(source);
	}
	void dfs(int source,vector<vector<int>> &adj,vector<bool> &vis){
	    vis[source]=true;
	    for(auto neighbour:adj[source]){
	        if(vis[neighbour]==false){
	            dfs(neighbour,adj,vis);
	        }
	    }
	    
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<vector<int>> adjList(V);
        // vector<int> adjListRev[V+1];
        for(int i=0;i<V;i++){
            
        vector<int> edge=adj[i];
            for(auto s:edge){
                adjList[s].push_back(i);
            }
            
            
        }
        stack<int> st;
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                dfsStack(i,adj,vis,st);
            }
        }
        fill(vis.begin(),vis.end(),false);
        // cout<<st.size()<<endl;
        int count=0;
        while(st.empty()==false){
            int el=st.top();
            st.pop();
            if(vis[el]==false){
                
            dfs(el,adjList,vis);
            count++;
            }
            
        }
        return count;
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends