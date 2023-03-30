class Solution {
public:
    static bool myComp(pair<int,int> p1,pair<int,int> p2){
        return p1.second>p2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        vector<pair<int,int>> ans;
        for(auto el:nums){
           
            mp[el]++;
        }
        for(auto ch:mp){
            ans.push_back({ch.first,ch.second});
        }
        sort(ans.begin(),ans.end(),myComp);
        int i=0;
        vector<int> ans1;
        while(i<k){
            ans1.push_back(ans[i].first);
                i++;
        }
        
        return ans1;
    }
};