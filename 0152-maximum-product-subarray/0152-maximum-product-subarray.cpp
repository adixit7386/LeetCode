class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxTillNow=nums[0];
        int minTillNow=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(maxTillNow,minTillNow);
            }
                maxTillNow=max(maxTillNow*nums[i],nums[i]);
                minTillNow=min(minTillNow*nums[i],nums[i]);
                ans=max({ans,minTillNow,maxTillNow});
            
        }
        return ans;
    }
};