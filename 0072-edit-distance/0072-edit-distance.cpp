class Solution {
public:
int editDist(string s1,string s2,int m,int n,vector<vector<int>>& dp){
    if(m==0)return n;
    if(n==0)return m;
    if(dp[m][n]==-1){

    if(s1[m-1]==s2[n-1]) return dp[m][n]=editDist(s1,s2,m-1,n-1,dp);
    dp[m][n]=1+min({editDist(s1,s2,m-1,n,dp),editDist(s1,s2,m,n-1,dp),editDist(s1,s2,m-1,n-1,dp)});
    }
    return dp[m][n];
}
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=0;i<=m;i++){
            dp[0][i]=i;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=-1;
            }
        }
        return editDist(word1,word2,word1.size(),word2.size(),dp);
    }
};