class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        
        
        vector<int> dp(n,n);
        dp[n-1]=0;
        for(int i=n-1;i>=1;i--){
            
            for(int j=i-1;j>=0;j--){
                
                if(nums[j]+j>=i){
                    dp[j]=(min(dp[j],dp[i]+1));
                }
            }
        }
        return dp[0];
    }
};