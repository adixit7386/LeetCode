class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        return sum-(nums.size()*(*min_element(nums.begin(),nums.end())));
        
    }
};