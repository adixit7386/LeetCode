class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
        for(int i=0;i<strs.size();i++){
            string k=strs[i];
            sort(k.begin(),k.end());
            
                mp[k].push_back(strs[i]);
                
                
            
        }
        for(auto s:mp){
            ans.push_back(s.second);
        }
        return ans;
    }
};