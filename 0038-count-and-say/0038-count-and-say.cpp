class Solution {
    private:
    vector<string>dp;
public:
void func(int x)
    {
        string s = dp[x-1];
        string ans="";
        int i, n= s.length();
        int curr=0,c=0;
        for(i=0;i<n;i++)
        {
            if(i==0) 
            {
                curr=s[i]-'0';
                c++;
            }
            else{
                if(s[i]!=s[i-1])
                {   
                   string temp="";
       temp+=to_string(c);
       temp+=to_string(curr);
       ans+=temp;
                    c=1;
                    curr=s[i]-'0';
                }
                else{
                    c++;
                }
            }
        }
       string temp="";
       temp+=to_string(c);
       temp+=to_string(curr);
       ans+=temp;
        dp[x]=ans;
    }
    string countAndSay(int n) {
        dp.resize(n);
        dp[0]="1";
        for(int i=1;i<n;i++)
        {
            func(i);
        }
        return dp[n-1];
    }
};