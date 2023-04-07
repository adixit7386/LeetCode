class Solution {
public:
   
    int deleteAndEarn(vector<int>& nums) {
       int maxElement=*max_element(nums.begin(),nums.end());
        
       vector<int> dp(maxElement+1,0);
        for(auto i:nums){
            dp[i]++;
        }
        for(int i=1;i<=maxElement;i++){
            dp[i]=dp[i]*i;
        }
        for(int i=2;i<=maxElement;i++){
            dp[i]=max(dp[i-1],dp[i]+dp[i-2]);
            
        }
        return dp[maxElement];
    }
};