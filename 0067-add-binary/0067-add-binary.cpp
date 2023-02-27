class Solution {
public:
    char binSum(int a ,int b,int& c){
        int sum=a+b+c;
        if(sum==3){
            c=1;
            return '1';
        }else if(sum==2){
            c=1;
            return '0';
        }else if(sum==1){
            c=0;
            return '1';
        }else{
            c=0;
            return '0';
        }
    }
    string addBinary(string a, string b) {
        int c=0;
        int i=a.size()-1,j=b.size()-1;
        string ans="";
        while(i>=0&&j>=0){
            int digit1=a[i]=='1'?1:0;
            int digit2=b[j]=='1'?1:0;
            ans+=binSum(digit1,digit2,c);
            i--;
            j--;
            
        }
        while(i>=0){
            int digit1=a[i]=='1'?1:0;
            
            ans+=binSum(digit1,0,c);
            i--;
            
        }
        while(j>=0){
            int digit2=b[j]=='1'?1:0;
            ans+=binSum(0,digit2,c);
            j--;
            
        }
        if(c==1){
            ans+='1';
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    
    }
    
};