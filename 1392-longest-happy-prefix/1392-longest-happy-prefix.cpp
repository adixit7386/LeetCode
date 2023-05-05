class Solution {
public:
    string longestPrefix(string s) {
        int n=s.length();
        int arr[n];
        int len=0;
        arr[0]=len;
        int i=1;
        int maxi=0;
        while(i<n){
            if(s[i]==s[len]){
                len++;
                arr[i]=len;
                cout<<arr[i]<<endl;
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
        return s.substr(0,arr[n-1]);
        
    }
};