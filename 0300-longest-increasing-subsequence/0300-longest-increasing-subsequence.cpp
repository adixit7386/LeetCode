#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            int dpsize=dp.size();
            int lbound=
            lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
            if(lbound<dpsize){
                dp[lbound]=nums[i];
            }else{
                dp.push_back(nums[i]);
            }
        }
        return dp.size();
    }
};