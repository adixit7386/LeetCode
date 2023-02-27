class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        while(columnNumber>0){
            columnNumber-=1;
            
            int digit=columnNumber%26;
            char Ch='A'+digit;
            ans=Ch+ans;
            columnNumber/=26;
            
        }
        return ans;
       
    }
};