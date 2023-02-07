class Solution {
public:
//     int minCoins(vector<int>& coins,int n,int sum){
//         if(sum==0){
//             return 0;
//         }
//         if(n==0){
//             return -1;
//         }
        
//         int res1=minCoins(coins,n-1,sum);
//         int res2=-1;
//         if(coins[n-1]<=sum){
//             res2=minCoins(coins,n,sum-coins[n-1]);
//         }
//         if(res2!=-1){
//             res2++;
//         }
        
//         return res1==-1?res2:res2==-1?res1:min(res1,res2);
//     }
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        
        vector<vector<int>> dp(n+1,vector<int> (amount+1,-1));
        
        
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                
                int res1=dp[i-1][j];
                int res2=-1;
                if(coins[i-1]<=j){
                    res2=dp[i][j-coins[i-1]];
                }
                if(res2!=-1){
                    res2++;
                }
                
                if(res1==-1){
                    dp[i][j]=res2;
                }else{
                    if(res2==-1){
                        dp[i][j]=res1;
                    }else{
                        dp[i][j]=min(res1,res2);
                    }
                }
            }
        }
        return dp[n][amount];        // return minCoins(coins,coins.size(),amount);
    }
    
};