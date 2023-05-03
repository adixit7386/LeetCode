class Solution {
public:
    vector<string> ansArr;
    void generate(int countOpen,int countClose,int n,string ans){
        if(ans.size()==2*n){
            ansArr.push_back(ans);
            return;
        }
        if(countOpen==countClose){
            if(countOpen>=1)
            generate(countOpen-1,countClose,n,ans+"(");
        }else if(countOpen<n){
            if(countOpen>=1)
            generate(countOpen-1,countClose,n,ans+"(");
            if(countClose>=1)
            generate(countOpen,countClose-1,n,ans+")");
        }else{
            if(countClose>=1)
            generate(countOpen,countClose-1,n,ans+")");

        }
    }
    vector<string> generateParenthesis(int n) {
        generate(n,n,n,"");
        return ansArr;
    }
};