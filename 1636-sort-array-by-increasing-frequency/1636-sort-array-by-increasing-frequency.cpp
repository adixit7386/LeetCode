class Solution {
public:
    static 
//     static bool myComp(int a,int b){
//         if(mp[a]==mp[b]){
//             return a>b;
//         }
//         return mp[a]<mp[b];
        
//     }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto element:nums){
            mp[element]++;
        }
        sort(nums.begin(),nums.end(),[&](int a,int b){
            return mp[a]==mp[b] ?a>b:mp[a]<mp[b];
        });
        return  nums;
    }
};