class Solution {
public:
    bool isPalindrome(int x) {
        string s=to_string(x);
        string t=s;
        int k;
        reverse(s.begin(),s.end());
        return s==t;
    }
};