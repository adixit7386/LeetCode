//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long>> dp(N+1,vector<long long> (sum+1,0));
        
        for(int i=0;i<=N;i++){
            dp[i][0]=1;
        }
        
        
        // if(sum==0){
        //     return 1;
        // }
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=sum;j++){
                long long res=dp[i-1][j];
                if(coins[i-1]<=j){
                    res+=dp[i][j-coins[i-1]];
                }
                dp[i][j]=res;
            }
        }
        return dp[N][sum];
        // if(N==0){
        //     return 0;
        // }
        
        // int res=count(coins,N-1,sum);
        
        // if(coins[N-1]<=sum){
        //     res+=count(coins,N,sum-coins[N-1]);
        // }
        
        // return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends