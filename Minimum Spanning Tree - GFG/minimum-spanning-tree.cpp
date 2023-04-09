//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
    //   for(int i=0;i<V;i++){
    //       for(auto vec:adj[i]){
    //           for(auto el:vec){
    //               cout<<el<<" ";
    //           }
    //           cout<<endl;
    //       }
    //       cout<<endl;
    //   }
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
       vector<bool> vis(V,false);
       pq.push({0,0});
       int res=0;
       while(!pq.empty()){
           pair<int,int> pt=pq.top();
           pq.pop();
           if(vis[pt.second])continue;
           vis[pt.second]=true;
           res+=pt.first;
           
           for(auto ngb:adj[pt.second]){
               int edgewt=ngb[1];
               int edgenode=ngb[0];
               if(vis[edgenode]==false){
                   pq.push({edgewt,edgenode});
               }
           }
       }
       return res;
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends