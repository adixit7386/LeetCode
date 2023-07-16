class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        vector<int> dp(n,1);
            // dp[0]=1;
            for(int i=1;i<n;i++){
                int res=dp[i];
                for(int j=0;j<i;j++){
                    if(pairs[i][0]>pairs[j][1]){
                        res=max(res,1+dp[j]);
                    }
                }
                dp[i]=res;
            }
        return dp[n-1];
    }
};