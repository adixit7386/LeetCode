class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start=0;
        for(int end=0;end<nums.size();end++)
            if(nums[end]!=0)
                swap(nums[end],nums[start++]);
    }
};