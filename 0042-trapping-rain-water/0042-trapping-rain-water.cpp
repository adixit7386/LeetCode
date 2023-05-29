class Solution {
public:
    int trap(vector<int>& prices) {
        int n=prices.size();
        vector<int> leftMax(n,0);
        vector<int> rightMax(n,0);


        int maxi=prices[0];

        for(int i=0;i<n;i++){
            leftMax[i]=max(maxi,prices[i]);
            maxi=max(maxi,prices[i]);
        }
        maxi=prices[n-1];

        for(int i=n-1;i>=0;i--){
            rightMax[i]=max(maxi,prices[i]);
            maxi=max(maxi,prices[i]);
        }

        int profit=0;

        for(int i=0;i<n;i++){
            profit+=(prices[i]-min(leftMax[i],rightMax[i]));
        }
        


        return profit*-1;

    }
};