
class Solution {
public:
    bool isFeasible(vector<int> &a,vector<int> &b){
        return a[0]==b[0] || a[1]==b[1];
    }
    void dfs(int source,vector<vector<int>> &stones,vector<bool> &vis){
        vis[source]=true;
        for(int i=0;i<stones.size();i++){
            if(vis[i]==false){
                if(isFeasible(stones[source],stones[i])){
                    dfs(i,stones,vis);
                }
            }
        }
        
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int count=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                dfs(i,stones,vis);
                count++;
                    
            }
        }
        return n-count;
        
    }
};