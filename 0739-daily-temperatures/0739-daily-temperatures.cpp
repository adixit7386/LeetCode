class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums2) {
        int n=nums2.size();
        stack<int> st;
        
        vector<int> nextGt(n,0);
        for(int i=n-1;i>=0;i--){
            while(st.empty()==false && nums2[st.top()]<=nums2[i]){
                st.pop();
            }
            nextGt[i]=st.empty()==true?-1:st.top();
            
            st.push(i);
        }
        for(int i=0;i<nextGt.size();i++){
            if(nextGt[i]==-1){
                nextGt[i]=0;
                continue;
            }else{
                nextGt[i]=nextGt[i]-i;
            }
        }
        return nextGt;
    }
};