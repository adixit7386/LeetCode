//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int performOp(int a,int b,char op){
        // int a=a-'0';
        // int b=b-'0';
        if(op=='+'){
            return a+b;
        }else if(op=='-'){
            return a-b;
        }else if(op=='*'){
            return a*b;
        }else{
            return a/b;
        }
    }
    bool isSymbol(char ch){
        if(ch=='+'||ch=='*'||ch=='-'||ch=='/'){
            return true;
        }
        return false;
    }
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        for(auto ch:S){
            if(isSymbol(ch)){
                int a=st.top();st.pop();
                int b=st.top();st.pop();
                int c=performOp(b,a,ch);
                st.push(c);
            }else{
                int a=ch-'0';
                st.push(a);
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends