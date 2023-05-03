class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string temp;
        for(int i=0;i<path.size();i++){
            if(path[i]=='/'){
                continue;
            }
            while(i<path.size()&&path[i]!='/'){
                temp+=path[i];
                i++;
            }
            if(temp=="."){
                
            }else if(temp==".."){
                if(!st.empty())
                st.pop();
            }else{
                st.push(temp);
            }
            temp="";
        }
        string ans="";
        while(st.empty()==false){
            ans="/"+st.top()+ans;
            st.pop();
        }
        if(ans.size()==0){
            return "/";
        }
        return ans;
    }
};