class Solution {
public:

    int superEggDrop(int e, int f) {
        
        vector<vector<int>> dp(e+1,vector<int> (f+1,f));
        
        for(int i=0;i<=f;i++){
            dp[1][i]=i;
            
        }
        for(int i=0;i<=e;i++){
            dp[i][1]=1;
            dp[i][0]=0;
            
        }
        
       
        
        
        
        for(int i=2;i<=e;i++){
            for(int j=2;j<=f;j++){
                
                int l=1,h=j,temp=0,ans=100000;
                 while(l<=h)
                 {
                    int mid=(l+h)/2;
                    int left= dp[i-1][mid-1]; //egg broken check for down floors of mid
                    int right= dp[i][j-mid];  // not broken check for up floors of mid
                    temp=1+max(left,right);          //store max of both 
                    if(left<right){                  //since right is more than left and we need more in worst case 
                      l=mid+1;                       // so l=mid+1 to gain more temp for worst case : upward
                    }
                    else                             //left > right so we will go downward 
                    {    
                        h=mid-1;
                    }
                    ans=min(ans,temp);               //store minimum attempts
                 }
                 dp[i][j]=ans;
            }
        }
        
        return dp[e][f];
        
        
        
    }
};