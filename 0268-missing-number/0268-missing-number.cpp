class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorSum=0;
        for(int i=0;i<=nums.size();i++){
            xorSum^=i;
        }
        int arrXorSum=0;
        for(int i=0;i<nums.size();i++){
            arrXorSum^=nums[i];
        }
        return xorSum^arrXorSum;
    }
};