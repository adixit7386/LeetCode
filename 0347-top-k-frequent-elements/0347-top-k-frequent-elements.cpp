class Solution {
public:
    static bool myComp(pair<int,int> p1,pair<int,int> p2){
        return p1.second>p2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto el:nums){
           
            mp[el]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto ch:mp){
            pq.push({ch.second,ch.first});
        }
        
        
       
        vector<int> ans1;
        while(k--){
           ans1.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans1;
    }
};