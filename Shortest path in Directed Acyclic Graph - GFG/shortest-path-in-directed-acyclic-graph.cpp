//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void shortestPath(vector<vector<pair<int, int>>> adj, int source, vector<int> &dist)
{
   
    // Using BFS

    queue<int> q;
    q.push(source);
    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        for (auto neighbor : adj[vertex])
        {
            dist[neighbor.first] = min(dist[neighbor.first], dist[vertex] + neighbor.second);
            q.push(neighbor.first);
        }
    }
}
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int, int>>> adj(n);
        for(auto vec:edges){
            adj[vec[0]].push_back({vec[1], vec[2]});
        }
        vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    shortestPath(adj, 0, dist);
    for(auto &el:dist){
        if(el==INT_MAX){
            el=-1;
        }
    }
    return dist;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends