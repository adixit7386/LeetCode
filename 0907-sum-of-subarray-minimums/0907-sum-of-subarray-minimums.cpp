class Solution {
public:
    vector<int> nextSmaller;
    vector<int> prevSmaller;
    void fillNextSmallerPrevSmaller(vector<int> &arr){
        int n=arr.size();
        prevSmaller.resize(n,-1);
        nextSmaller.resize(n,n);
        
        stack<int> st;
        
        for(int i=0;i<n;i++){
            while(st.empty()==false && arr[st.top()]>=arr[i]){
                int popped=st.top();st.pop();
                nextSmaller[popped]=i;
            }
            
            prevSmaller[i]=st.empty()==true?-1:st.top();
            
            st.push(i);
        }
        while(st.empty()==false){
            nextSmaller[st.top()]=n;
            st.pop();
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        
        fillNextSmallerPrevSmaller(arr);
        
        long long ans=0;
        unsigned int mod = 1000000007;
        
        for(int i=0;i<n;i++){
            long long elementsAhead=nextSmaller[i]-i-1;
            long long elementsBefore=i-prevSmaller[i]-1;
            
            long long calCount=elementsAhead+elementsBefore+1;
            calCount= (calCount +(elementsAhead*elementsBefore)%mod)%mod;
            
            ans=  (ans+ (arr[i]*calCount)%mod)%mod;
        }
        return ans;
    }
};