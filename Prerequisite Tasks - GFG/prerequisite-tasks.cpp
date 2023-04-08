//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isCycle(vector<int> adj[],int source,vector<bool> &vis,vector<bool> &recSt){
        vis[source]=true;
        recSt[source]=true;
        for(auto ngb:adj[source]){
            if(vis[ngb]==false){
                if(isCycle(adj,ngb,vis,recSt))
                    return true;
            }else if(recSt[ngb]==true){
                return true;
            }
        }
        recSt[source]=false;
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> adj[N];
	    int source=-1;
	    for(auto pairs:prerequisites){
	        if(pairs.first==pairs.second){
	            return false;
	        }
	       // if(source==-1){
	        adj[pairs.first].push_back(pairs.second);
	    }
	    vector<bool> vis(N,false);
	    vector<bool> recSt(N,false);
	    for(int i=0;i<N;i++){
	        if(vis[i]==false){
	            bool flag=isCycle(adj,i,vis,recSt);
	            if(flag==true){
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
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends