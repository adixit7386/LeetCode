class Solution {
public:
       bool isPalindrome(const string& s, int i, int j) {
           
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        for(int i=0;i<(s.length()-1)/2;i++){
            int j=s.length()-i-1;
            if(s[i]!=s[j]){
                return (isPalindrome(s,i+1,j)||isPalindrome(s,i,j-1));
            }
        }
        return true;
    }
};