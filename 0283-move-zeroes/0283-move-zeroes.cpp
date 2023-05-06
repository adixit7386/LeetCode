class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        for(int end=0;end<n;end++){
            if(nums[end]!=0){
                swap(nums[end],nums[start]);
                start++;
            }else{
                
            }
        }
        
    }
};