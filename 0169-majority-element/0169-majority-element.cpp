class Solution {
public:
    int majorityElement(vector<int>& nums) {
        pair<int,int> pr={nums[0],1};
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==pr.first)
                pr.second++;
            else pr.second--;

            if(pr.second==0){
                pr={nums[i],1};
            }
        }
        return pr.first;
    }
};