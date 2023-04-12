class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto flight:flights){
            adj[flight[0]].push_back({flight[1],flight[2]});
        }
        if(src==dst){
            return 0;
        }
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        //steps dest price
        
        while(q.empty()==false){
            pair<int,pair<int,int>> pr=q.front();
            q.pop();
            int steps=pr.first;
            int dest=pr.second.first;
            int cost=pr.second.second;
            
            if(steps>k){
                continue;
            }
            for(auto ngb:adj[dest]){
                if(cost+ngb.second<dist[ngb.first] && steps<=k){
                    dist[ngb.first]=cost+ngb.second;
                    q.push({steps+1,{ngb.first,cost+ngb.second}});
                }
            }
        }
        int ans=dist[dst];
       return ans==INT_MAX?-1:ans;
    }
};