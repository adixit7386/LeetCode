class Solution {
public:
    
    int countSubsets(vector<string>& strs,int size, int m, int n,vector<vector<vector<int>>> &dp){
       
        if(m<0||n<0){
            return -1;
        }
        
        
        if(dp[size][m][n]!=-1){
            return dp[size][m][n];
        }
        
        int countOnes=count(strs[size-1].begin(), strs[size-1].end(), '1');
        int countZeroes=count(strs[size-1].begin(), strs[size-1].end(), '0');
        
        int include=countSubsets(strs,size-1,m-countZeroes,n-countOnes,dp);
        int notInclude=countSubsets(strs,size-1,m,n,dp);
        if(include!=-1){
            include++;
        }
        int res=max(include,notInclude);
        if(res==-1){
            dp[size][m][n]=-1;
        }else{
            dp[size][m][n]=res;
        }
        
        return dp[size][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size=strs.size();
        vector<vector<vector<int>>> dp(size+1,vector<vector<int>> (m+1,vector<int> (n+1,-1)));
        
         
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    
                        dp[0][j][k]=0;
                    
                }
            }
        
        return countSubsets(strs,strs.size(),m,n,dp);
    }
};