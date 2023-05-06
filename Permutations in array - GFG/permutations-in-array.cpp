//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // long long maxElement(long long a[],int n){
    //     long long maxEl=INT_MIN;
    //     for(int i=0;i<n;i++){
    //         maxEl=max(maxEl,a[n]);
    //     }
    //     return maxEl;
    // }
    bool isPossible(long long a[], long long b[], int n, long long k) {
        // Your code goes here
        // long long maxa=maxElement(a,a+n);
        // long long maxb=maxElement(b,b+n);
        // return maxa+maxb>=k;
        sort(a,a+n);
        sort(b,b+n,greater<int>());
        for(int i=0;i<n;i++){
            if(a[i]+b[i]<k){
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        long long a[n + 2], b[n + 2];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        Solution ob;
        cout << ob.isPossible(a, b, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends