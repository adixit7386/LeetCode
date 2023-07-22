class Solution {
public:
    int maxSubSum(vector<int>& nums){
         int maxSum = INT_MIN;
        int currentSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
            
            if (currentSum < 0) {
                currentSum = 0;
            }
        }
        
        return maxSum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int subSum2=maxSubSum(nums);
        int maxElement=*max_element(nums.begin(),nums.end());
        if(maxElement<0)
        return maxElement;
        int sum=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=-1*nums[i];
        }
        
        int subSum=maxSubSum(nums);
        // cout<<subSum<<endl;
        return max(sum+subSum,subSum2);
    }
};