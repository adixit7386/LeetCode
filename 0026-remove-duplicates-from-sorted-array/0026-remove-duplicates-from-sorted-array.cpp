class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==1 || n==0)return n;
        int start=1;
        
        for(int end=start;end<n;end++){
            if(nums[end]==nums[start-1]){
                continue;
            }else{
                nums[start]=nums[end];
                start++;
            }
        }
        return start;
    }
};