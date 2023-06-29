class Solution {
public:
    int lis(vector<int> &nums,int ind,int prev_ind,vector<vector<int>> &dp){
        //base case
        if(ind>=nums.size())return 0;
        if(dp[ind][prev_ind+1]!=-1)return dp[ind][prev_ind+1];
        int res=lis(nums,ind+1,prev_ind,dp);
        if(prev_ind==-1||nums[ind]>nums[prev_ind]){
            res=max(res,1+lis(nums,ind+1,ind,dp));
        }


        return dp[ind][prev_ind+1]=res;


    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        
        return lis(nums,0,-1,dp);
    }
};