class Solution {
public:
    int countWays(string s,int i,int taken,vector<vector<int>>& dp){
        if(i>=s.length()){
            return 1;
        }
        int count=0;
        if(dp[taken][i]==-1){
            
        
        if(!taken){
            int valid=(s[i]-'0')+(s[i-1]-'0')*10;
            if(valid>0 && valid<27){
                count+=countWays(s,i+1,1,dp);
            }
            
        }else{
            //include current character 
            
            int valid=s[i]-'0';
            if(valid>0){
                count+=countWays(s,i+1,1,dp);
            }else{
               dp[taken][i]=count;
                return dp[taken][i];
            }
            
            
            //skip current character
            if(i<s.length()-1)
            count+=countWays(s,i+1,0,dp);
            
            
        }
             dp[taken][i]=count;
            
        }
       
        return dp[taken][i];
        
    }
    int numDecodings(string s) {
        vector<vector<int>> dp(2,vector<int> (s.size()+1,-1));
        dp[0][s.size()]=1;
        dp[1][s.size()]=1;
        
        
        return countWays(s,0,1,dp);
        
    }
};