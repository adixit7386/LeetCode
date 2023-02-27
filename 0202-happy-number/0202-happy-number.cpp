class Solution {
public:
    bool isNotHappy(int n,unordered_set<int> &st) {
        if(n==1){
            return true;
        }
        
        
        int number=0;
        while(n){
            int digit=n%10;
            number+=digit*digit;
            n/=10;
        }
        if(st.find(number)!=st.end()){
            return false;
        }
        st.insert(number);
        return isNotHappy(number,st);
    }
    bool isHappy(int n){
        unordered_set<int> st;
        return isNotHappy(n,st);
        
    }
};