class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m=s1.length();
        int n=s2.length();
        vector<int> second(n+1,0);
        vector<int> third(n+1,0);
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    third[j]=1+second[j-1];
                }else{
                    third[j]=max(second[j],third[j-1]);
                }
            }
            second=third;
        }
        return third[n];

    }
};