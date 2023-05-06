class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int middle=0;
        while(middle<=end){
            if(nums[middle]==0){
                swap(nums[middle],nums[start]);
                start++;
                middle++;
            }else if(nums[middle]==1){
                middle++;
            }else{
                swap(nums[middle],nums[end]);
                end--;
            }
        }
        return;
    }
};