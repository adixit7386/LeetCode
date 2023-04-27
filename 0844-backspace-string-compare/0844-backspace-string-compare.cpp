class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        for(auto ch:s){
            if(ch=='#'){
                if(st.empty())continue;
                st.pop();
            }else{
                st.push(ch);
            }
        }
        reverse(t.begin(),t.end());
        int charOmmited=0;
        for(int i=0;i<t.length();i++){
            char ch=t[i];
            if(ch=='#'){
                charOmmited++;
            }else{
                if(charOmmited){
                    charOmmited--;
                    continue;
                }
                if(st.size()==0)return false;
                if(t[i]!=st.top()){
                    return false;
                }
                st.pop();
                
                
            }
        }
        return st.size()==0;
    }
};