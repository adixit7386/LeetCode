class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        int a=nums[0],b=max(nums[0],nums[1]),c;
        for(int i=3;i<=n;i++){
            c=b;
            c=max(c,nums[i-1]+a);
            a=b;
            b=c;
        }
        return c;
        
    }
};