class Solution {
public:
    void dfs(int i,vector<bool> &visited, vector<vector<int>> &graph,vector<bool>&isSafe){
        visited[i]=true;
        bool flag=false;
        for(auto ngb:graph[i]){
            if(visited[ngb]==false){
                dfs(ngb,visited,graph,isSafe);
            }
            if(isSafe[ngb]==false){
                flag=true;
            }
            
        }
        if(flag==false)
        isSafe[i]=true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> isSafe(n,false);
        vector<bool> visited(n,false);
        for(int i=0;i<graph.size();i++){
            
            vector<int> ngb=graph[i];
            if(ngb.size()==0){
                isSafe[i]=true;
            }
            cout<<isSafe[i]<<endl;
        }
        for(int i=0;i<n;i++){
            if(visited[i]==false)
            dfs(i,visited,graph,isSafe);
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(isSafe[i]==true)
            ans.push_back(i);
        }
        return ans;
    }
};