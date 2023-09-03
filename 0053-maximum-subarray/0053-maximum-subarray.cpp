class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int ans=INT_MIN;
         int len=nums.size();
         int curr=0;
         for(int i=0;i<len;i++){
             curr+=nums[i];
             ans=max(ans,curr);
             if(curr<0){
                 curr=0;
             }
         }
         return ans;
    }
};