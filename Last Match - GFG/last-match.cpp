//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    void longestPrefix(string s,int arr[]) {
        int n=s.length();
        
        int len=0;
        arr[0]=len;
        int i=1;
        int maxi=0;
        while(i<n){
            if(s[i]==s[len]){
                len++;
                arr[i]=len;
                // cout<<arr[i]<<endl;
                i++;
                // maxi=max(maxi,len);
            }else{
                if(len==0){
                    arr[i]=0;
                    
                    i++;
                }else{
                    len=arr[len-1];
                }
            }
        }
        
        
    }
    int findLastOccurence(string str,string pat){
        //Code Here
        int m=str.length();
        int n=pat.length();
        int lps[n];
        fill(lps,lps+n,0);
        longestPrefix(pat,lps);
        int i=0;
        int ans=-1;
        int j=0;
        while(i<m){
            if(str[i]==pat[j]){
                i++;
                j++;
            }
            if(j==n){
                ans=i-j;
                j=lps[j-1];
                
            }else if(i<m && str[i]!=pat[j]){
                if(j==0){
                    i++;
                }else {
              
                    j=lps[j-1];};
                
            }
        }
        if(ans==-1)return -1;
        return ans+1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A>>B;
        Solution ob;
        cout<<ob.findLastOccurence(A,B)<<"\n";
        
    } 
    return 0; 
}
// } Driver Code Ends