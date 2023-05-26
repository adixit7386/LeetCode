class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums,int starts,int newTarget) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        // if(n<3){
        //     return {};
        // }
        vector<vector<int>> finalAns;
        for(int i=starts;i<n-2;i++){
            
            if(i>starts && nums[i]==nums[i-1]){
                continue;
            }
            int start=i+1;
            int end=n-1;
            long long target=newTarget;
            target-=nums[i];
            while(start<end){
                long long sum=nums[start]+nums[end];
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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n<4)return {};
        vector<vector<int>> finalAns;
        for(int i=0;i<n-3;i++){
            if(i>0&& nums[i]==nums[i-1])continue;
            vector<vector<int>> subAns=threeSum(nums,i+1,target-nums[i]);
            vector<int> newSubAns;
            if(subAns.size()!=0){
                for(auto subAns2:subAns){
                    newSubAns=subAns2;                    
                    newSubAns.push_back(nums[i]);
                    sort(newSubAns.begin(),newSubAns.end());
                    finalAns.push_back(newSubAns);
                }
                    
                   
                    
            }
            
        }
        return finalAns;
    }
    
};