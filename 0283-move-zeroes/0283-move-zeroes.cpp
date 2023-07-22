class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                swap(nums[res],nums[i]);
                res++;
            }
            
        }
        // return res+1;
    }
};