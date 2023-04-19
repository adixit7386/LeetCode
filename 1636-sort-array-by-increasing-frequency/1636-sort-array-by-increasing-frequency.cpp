
unordered_map<int,int> mp;
  bool myComp(int a,int b){
        if(mp[a]==mp[b]){
            return a>b;
        }
        return mp[a]<mp[b];
        
    }
class Solution {
public:
    static 
  
    vector<int> frequencySort(vector<int>& nums) {
        
        for(auto element:nums){
            mp[element]++;
        }
        sort(nums.begin(),nums.end(),myComp);
        mp.clear();
        return  nums;
    }
};