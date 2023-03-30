//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        if(n==0){
            return 0;
        }
        vector<int> dp(n+1,0);
        
        for(int i=1;i<=n;i++){
            int ans=INT_MIN;
                dp[i]=INT_MIN;
            if(x<=i){
            ans=max(ans,1+dp[i-x]);
            }
            if(y<=i){
            ans=max(ans,1+dp[i-y]);
            }
            if(z<=i){
            ans=max(ans,1+dp[i-z]);
            }
            
            dp[i]=ans;
        }
        
        if(dp[n]<0)return 0;
        else return dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends