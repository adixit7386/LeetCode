#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int superEggDrop(int k, int n) {
        
//         vector<vector<int>> dp(e+1,vector<int> (f+1,0));
//         for(int i=0;i<=f;i++){
        
//             dp[1][i]=i;
//         }
//         for(int i=1;i<=e;i++){
//             dp[i][1]=1;
            
//         }
        
//         for(int i=2;i<=e;i++){
//             for(int j=2;j<=f;j++){
//                 int res=INT_MAX;
//                 for(int p=1;p<=j;p++){
//                     int m=max(dp[i][j-p],dp[i-1][p-1]);
//                     res=min(res,1+m);
//                 }
//                 dp[i][j]=res;
//                 cout<<dp[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
        
//         return dp[e][f];
        
        // if(k==1){
        //     return n;
        // }
        // if(n<=1){
        //     return n;
        // }
        // int res=n+1;
        // for(int i=1;i<=n;i++){
        //     res=min(res,1+max(superEggDrop(k-1,i-1),superEggDrop(k,n-i)));
        // }
        // return res;
        
        vector<vector<int>> dp(n+1,vector<int> (k+1,n+1));
        for(int i=0;i<=k;i++){
            dp[0][i]=0;
            dp[1][i]=1;
        }
        for(int i=0;i<=n;i++){
            dp[i][1]=i;
        }
        
        for(int i=2;i<=n;i++){
            for(int j=2;j<=k;j++){
                dp[i][j]=n+1;
                // for(int l=1;l<=i;l++){
                //    dp[i][j]=min(dp[i][j],1+max(dp[l-1][j-1],dp[i-l][j])) ;
                // }
                
                int low=1,high=i;
                while(low<=high){
                    int mid=(low+high)/2;
                    
                    int left=dp[mid-1][j-1];
                    int right=dp[i-mid][j];
                    if(left<right){
                        low=mid+1;
                    }else{
                        high=mid-1;
                    }
                    dp[i][j]=min(dp[i][j],(1+max(left,right)));
                }
            }
        }
        return dp[n][k];
    }
};