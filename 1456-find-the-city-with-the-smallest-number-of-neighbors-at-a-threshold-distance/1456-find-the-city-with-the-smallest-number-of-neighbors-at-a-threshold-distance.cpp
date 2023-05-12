class Solution {
public:
    // int dfs(int source,vector<pair<int,int>> adj[],int threshold,vector<bool> &vis){
    //     vis[source]=true;

    // }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long long>> matrix(n,vector<long long> (n,INT_MAX));
        for(int i=0;i<n;i++)matrix[i][i]=0;

        for(auto edge:edges){
            matrix[edge[0]][edge[1]]=edge[2];
            matrix[edge[1]][edge[0]]=edge[2];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<n;i++){
            for(int u=0;u<n;u++){
               
                for(int v=0;v<n;v++){
                    if(matrix[u][i]==INT_MAX || matrix[i][v]==INT_MAX)continue;
                    matrix[u][v]=min(matrix[u][v],matrix[u][i]+matrix[i][v]);
                }
            }
        }
        int max=INT_MAX;
        int ans=n-1;
        for(int i=n-1;i>=0;i--){
            int count=0;
            for(int j=0;j<n;j++){
                cout<<matrix[i][j]<<" ";
                if(matrix[i][j]<=distanceThreshold){
                    count++;
                }
            }
            cout<<endl;
            if(count<max){
                ans=i;
                max=count;
            }
        }
        return ans;
    }
};