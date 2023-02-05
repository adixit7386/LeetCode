class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> st;
vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(st.find(target-nums[i])!=st.end()){
                
                ans.push_back(st.find(target-nums[i])->second);
                ans.push_back(i);
                sort(ans.begin(),ans.end());

                return ans;

            }

            st.insert({nums[i],i});



        
    }
    return ans;
}
};