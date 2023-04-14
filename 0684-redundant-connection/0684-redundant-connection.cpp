class DisjointSet{
    vector<int> rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }
    int findpar(int node){
        if(node==parent[node]){
            return node;
        }
        return findUPar(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u,int v){
         int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int max1=0;
        for(auto vec1:edges){
            max1=max({max1,vec1[0],vec1[1]});
        }
        vector<int> ans;
        DisjointSet ds=DisjointSet(max1);
        for(auto edge:edges){
            int par_x=ds.findpar(edge[0]);
            int par_y=ds.findpar(edge[1]);
            
            if(par_x==par_y){
                ans={edge[0],edge[1]};
            }
            
            ds.unionByRank(edge[0],edge[1]);
        }
        return ans;
    }
};