class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        if(n==1)return true;
        int i=0;
        if(nums[0]==0)return false;
        for(i=0;i<n && i<=maxi ;i++){
            nums[i]=max(maxi,nums[i]+i);
            if(maxi>=n-1)return true;
            maxi=max(maxi,nums[i]);
        }
        return false;
    }
};