class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        stack<int> st;
        
        unordered_map<int,int> nextGt;
        for(int i=n-1;i>=0;i--){
            while(st.empty()==false && nums2[st.top()]<=nums2[i]){
                st.pop();
            }
            nextGt[nums2[i]]=st.empty()==true?-1:nums2[st.top()];
            
            st.push(i);
        }
        for(auto &element:nums1){
            element=nextGt[element];
        }
        return nums1;
    }
};