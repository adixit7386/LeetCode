class Solution {
public:
    bool isValid(string str){
        if(str.length()==0)return false;
        if(str[0]=='0')return false;
        if(stoi(str)<=26)return true;
        return false;
    }
    int decodeWays(string s,int i){
        if(i>=s.length())return 1;
        //of digit 1;
        string str="";
        str+=s[i];
        int ans=0;
        if(isValid(str))
            ans=decodeWays(s,i+1);
        if(i>=s.length()-1)return ans;
        str+=s[i+1];
        if(isValid(str))
            return ans+decodeWays(s,i+2);
        return ans;

        //of digit 2


    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n+2,0);
        dp[n]=1;
        dp[n+1]=1;
        for(int i=n-1;i>=0;i--){
            string str="";
            str+=s[i];
            int ans=0;
            if(isValid(str))
                ans=dp[i+1];
            if(i>=n-1){
                dp[i]=ans;
                continue;
            }
            str+=s[i+1];
            if(isValid(str))
                dp[i]=ans+dp[i+2];
            else
            dp[i]=ans;
                
        }
        return dp[0];
    }
};