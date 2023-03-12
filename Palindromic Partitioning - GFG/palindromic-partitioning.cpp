//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            j--;
            i++;
        }
        return true;
    }
    int palindromePartition(string str,int i ,int j){
        if(isPalindrome(str,i,j)){
            return 0;
        }
        int res=INT_MAX;
        for(int k=i;k<j;k++){
            res=min(res,1+palindromePartition(str,i,k)+palindromePartition(str,k+1,j));
        }
        return res;
    }
    int palindromicPartition(string str)
    {
        
        int size=str.size();
        
        if(isPalindrome(str,0,size-1)){
            return 0;
        }
        
        vector<vector<int>> dp(size,vector<int> (size,0));
        
        for(int gap=1;gap<size;gap++){
            for(int i=0;i+gap<size;i++){
                int j=i+gap;
                if(isPalindrome(str,i,j)){
                    dp[i][j]=0;
                }else{
                    
                dp[i][j]=INT_MAX;
                for(int k=i;k<j;k++){
                    dp[i][j]=min(dp[i][j],1+dp[i][k]+dp[k+1][j]);
                }
                }
            }
        }
        
        return dp[0][size-1];
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends