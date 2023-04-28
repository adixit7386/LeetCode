class Solution {
public:
    int performOp(int a,int b,string op){
        // int a=a-'0';
        // int b=b-'0';
        if(op=="+"){
            return a+b;
        }else if(op=="-"){
            return a-b;
        }else if(op=="*"){
            return a*b;
        }else{
            return a/b;
        }
    }
    bool isSymbol(string ch){
        if(ch=="+"||ch=="*"||ch=="-"||ch=="/"){
            return true;
        }
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto ch:tokens){
            if(isSymbol(ch)){
                int a=st.top();st.pop();
                int b=st.top();st.pop();
                int c=performOp(b,a,ch);
                st.push(c);
            }else{
                int a=stoi(ch);
                st.push(a);
            }
        }
        return st.top();
    }
};