class Solution {
public:
    // void maxProdSubarray(vector<int> nums,int n,int product,int &ans){
    //     if(n==0){
    //         return ;
    //     }
    //     ans =max({ans,product*nums[n-1],nums[n-1]});
    //     maxProdSubarray(nums,n-1,product*nums[n-1],ans);
    //     maxProdSubarray(nums,n-1,nums[n-1],ans);
    // }
    int maxProduct(vector<int>& nums) {
       // int sum=INT_MIN;
       //  maxProdSubarray(nums,nums.size(),1,sum);
       //  return sum;
        int minTillNow=nums[0];
        int maxTillNow=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(minTillNow,maxTillNow);
                
            }
            minTillNow=min(minTillNow*nums[i],nums[i]);
            maxTillNow=max(maxTillNow*nums[i],nums[i]);
        
            ans=max({ans,minTillNow,maxTillNow});
        }
        return ans;
        
    }
};