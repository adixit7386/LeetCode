class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n<3){
            return {};
        }
        vector<vector<int>> finalAns;
        for(int i=0;i<n-2;i++){
            if(nums[i]>0){
                break;
            }
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int start=i+1;
            int end=n-1;
            int target=-1*nums[i];
            while(start<end){
                int sum=nums[start]+nums[end];
                if(sum>target){
                    end--;
                }else if(sum<target){
                    start++;
                }else{
                    vector<int> subAns={nums[i],nums[start],nums[end]};
                    finalAns.push_back(subAns);
                    start++;
                    end--;
                    while(start<end&& nums[start]==nums[start-1]){
                        start++;
                    }
                    while(start<end&& nums[end]==nums[end+1]){
                        end--;
                    }
                }
            }
            
        }
        return finalAns;
    }
};