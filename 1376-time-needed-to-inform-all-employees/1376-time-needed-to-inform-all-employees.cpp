class Solution {
public:
    int dfs(vector<int> adj[],int source,vector<int>& informTime){
        int maxi=0;
        for(auto element: adj[source]){
            maxi=max(maxi,dfs(adj,element,informTime));
        }
        return maxi+informTime[source];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<int> adj[n];
        for(int i=0;i<manager.size();i++){
            if(i!=headID)
            adj[manager[i]].push_back(i);
        }
//         {
// //         queue<int> q;
// //         int ans=0;
// //         // vector<bool> vis()
// //         q.push(headID);
// //         q.push(-1);
// //         int maxi=0;
// //         // int prevEmployee=0;
// //         while(q.size()>1){
// //             int employee=q.front();
// //             q.pop();
// //             if(employee==-1){
// //                 cout<<maxi<<endl;
// //                 ans+=maxi;
// //                 maxi=0;
// //                 q.push(-1);
// //             }else{
// //             for(auto subemp:adj[employee] ){
// //                 q.push(subemp);
// //                 maxi=max(maxi,informTime[employee]);
// //             }
            
// //             }
// //             // prevEmployee=employee;
// //         }
//     }
        return dfs(adj,headID,informTime);
    }
};