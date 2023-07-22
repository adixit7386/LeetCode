class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[res]){
                nums[++res]=nums[i];
                // res++;
            }
        }
        return res+1;
    }
};