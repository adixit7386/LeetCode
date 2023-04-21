class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> mp;
        for(auto ch:s){
            mp[ch]++;
        }
        vector<int> freq;
        for(auto element:mp){
            freq.push_back(element.second);
        }
        int n=freq.size();
        sort(freq.begin(),freq.end(),greater<int>());
        int ans=0;
        int i=0;
        for(i=1;i<n;i++){
            if(freq[i]>=freq[i-1]){
                int prev=freq[i];
                freq[i]=freq[i-1]-1;
                ans+=prev-freq[i];
            }
            if(freq[i]==0){
                break;
            }
        }
        if(i<n){
            while(i<n){
                ans+=freq[i];
                i++;
            }
        }
        return ans;
    }
};