class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        st.push(0);
        int ans=INT_MIN;
        for(int i=1;i<n;i++){
          
            while(st.empty()==false && heights[st.top()]>=heights[i]){
                int index=st.top();
                st.pop();
                int prev=st.empty()?-1:st.top();
                
                ans=max(ans,heights[index]*(i-prev-1));
            }
            st.push(i);
        }
        while(st.empty()==false){
                int index=st.top();
                st.pop();
                int prev=st.empty()?-1:st.top();
                ans=max(ans,heights[index]*(n-prev-1));
        }
        return ans;
    }
};