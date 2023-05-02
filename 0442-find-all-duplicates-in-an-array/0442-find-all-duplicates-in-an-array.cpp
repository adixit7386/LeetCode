class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums.size()+1;
        for(auto &el:nums){
            el--;
        }
        for(int i=0;i<n;i++){
            
            nums[nums[i]%maxi]+=maxi;
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]/maxi>1){
                ans.push_back(i+1);
            }
        }
        
        
        
        
        
        
        
        return ans;
    }
};