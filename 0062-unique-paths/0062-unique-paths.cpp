class Solution {
public:
    int uniquePaths(int m, int n) {
        
        // if(m==1&&n==1){
        //     return 1;
        // }
        // int top=0,left=0;
        // if(m>1){
        //     top=uniquePaths(m-1,n);
        // }
        // if(n>1){
        //     left=uniquePaths(m,n-1);
        // }
        // return top+left;
        vector<vector<int>> dp(m+1,vector<int> (n+1,1));
        for(int i=2;i<=m;i++){
            for(int j=2;j<=n;j++){
                int top=0,left=0;
                if(i>1){
                    top=dp[i-1][j];   
                }
                if(j>1){
                    left=dp[i][j-1];
                }
                dp[i][j]=top+left;
            }
        }
       
        return dp[m][n];
    }
};