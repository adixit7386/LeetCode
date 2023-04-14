//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(vector<int> adj[],int source,unordered_set<int> &st1,unordered_set<int> &st2,vector<bool> &vis){
        vis[source]=true;
        for(auto ngb:adj[source]){
            
                if(st1.find(source)!=st1.end()){
                    if(st1.find(ngb)!=st1.end()){
                        return false;
                    }
                    if(vis[ngb]==false){
                        
                    
                        st2.insert(ngb);
                        if(dfs(adj,ngb,st1,st2,vis)==false){
                            return false;
                        }
                    }
                        
                }else if(st2.find(source)!=st2.end()){
                    if(st2.find(ngb)!=st2.end()){
                        return false;
                    }
                    if(vis[ngb]==false){
                        st1.insert(ngb);
                        if(dfs(adj,ngb,st1,st2,vis)==false){
                            return false;
                        }
                    }
                }
            
        }
        return true;

    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<bool> vis(V,false);
	    unordered_set<int> st1;
	    unordered_set<int> st2;
	    for(int i=0;i<V;i++){
    	        if(vis[i]==false){
        	        st1.insert(i);
        	        if(dfs(adj,i,st1,st2,vis)==false){
        	          
        	            return false;
        	        }
	            }
	    }
	    return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends