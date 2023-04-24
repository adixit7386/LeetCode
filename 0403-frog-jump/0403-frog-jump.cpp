struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};
class Solution {
public:
    unordered_map<int,int> mp;
    unordered_map<pair<int,int>,bool,pair_hash> dp;
    // vector<vector
    bool cansCross(vector<int>& stones,int i,int k){
        if(i==stones.size()-1){
            return true;
        }
        if(dp.find({i,k})==dp.end()){
            
        
        int a=mp.find(stones[i]+k)!=mp.end()?mp[stones[i]+k]:-1;
        int b=mp.find(stones[i]+k-1)!=mp.end()?mp[stones[i]+k-1]:-1;
        int c=mp.find(stones[i]+k+1)!=mp.end()?mp[stones[i]+k+1]:-1;
        
        bool ans1= a!=-1?cansCross(stones,a,k):false;
        
        bool ans2=(b!=-1 && k!=1)?cansCross(stones,b,k-1):false;
        
        bool ans3= c!=-1?cansCross(stones,c,k+1):false;
        dp[{i,k}]=(ans1||ans2||ans3);
        }
        bool ans =dp[{i,k}];
        return ans;
        
    }
    bool canCross(vector<int>& stones) {
        // reverse(stones.begin(),stones.end());
        for(int i=0;i<stones.size();i++){
            mp[stones[i]]=i;
        }
        // return false;
        if(stones.size()==1){
            return true;
        }
        if(stones[1]!=stones[0]+1){
            return false;
        }
        
        return cansCross(stones,1,1);
    }
};