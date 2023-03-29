class Solution {
public:
//     int countSubsets(int size,int m,int n,unordered_map<int,pair<int,int>>& mp){
//         // if(m<0||n<0){
//         //     return -1;
//         // }
//         if(m==0&&n==0){
//             return 0;
//         }
//         if(size==0){
//             return 0;
//         }
//         int include=-1;
//         if(m>=mp[size-1].first&&n>=mp[size-1].second)
//         include=countSubsets(size-1,m-mp[size-1].first,n-mp[size-1].second,mp);
      
//         if(include!=-1){
//             include++;
//         }
//         int notinclude=countSubsets(size-1,m,n,mp);
       
//         // if(include==-1 && notinclude==-1){
//         //     return -1;
//         // }
//         // if(include==-1){
//         //     return notinclude;
//         // }
//         // if(notinclude==-1){
//         //     return include;
//         // }
//         return max(include,notinclude);
        
//     }
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        unordered_map<int,pair<int,int>> mp;
        
        for(int i=0;i<strs.size();i++){
            string st=strs[i];
            int count1s=0;
            int count0s=0;
            for(auto ch:st){
                if(ch=='1'){
                    count1s++;
                }
                if(ch=='0'){
                    count0s++;
                }
            }
            mp[i]={count0s,count1s};
        }
        // int ans=0;
        int size=strs.size();
        // ans=countSubsets(strs.size(),m,n,mp);
        // vector<vector<vector<int>>> dp(size+1,vector<vector<int>> (m+1,vector<int> (n+1,0)) );
        
    vector<vector<int>> prev(m+1,vector<int> (n+1,0)) ;
        vector<vector<int>> curr(m+1,vector<int> (n+1,0)) ;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                prev[i][j]=0;
                
            }
        }
        prev[0][0]=0;
        
        
        for(int i=1;i<=size;i++){
            
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    int include=-1;
                    if(j>=mp[i-1].first&&k>=mp[i-1].second)
                        include=prev[j-mp[i-1].first][k-mp[i-1].second];
                    if(include!=-1){
                        include++;
                    }
                    int notinclude=prev[j][k];
                    curr[j][k]=max(include,notinclude);
                }
            }
            prev=curr;
        }
     
        return prev[m][n];
        
        
    }
};