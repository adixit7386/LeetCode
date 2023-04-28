class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        stack<char> st;
        for(auto ch:s){
            if(st.empty()==true){
                st.push(ch);
            }else{
                if(ch==st.top()){
                    st.pop();
                }else{
                    st.push(ch);
                }
            }
        }
        while(st.empty()==false){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};