class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        if(n==0){
            return ans;
        }
        ans[1]=1;
        if(n==1){
            return ans;
        }
        ans[2]=1;
        if(n==2){
            return ans;
        }
        
        for(int i=3;i<=n;i++){
            if(i&1){
                ans[i]=ans[i/2]+1;
                
            }else{
                ans[i]=ans[i/2];
            }
        }
        return ans;
        
        
    }
};