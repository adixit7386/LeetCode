class Solution {
public:
    int indexOf(int idx,int n){
        return idx%n;
    }
        
    int maxScore(vector<int>& cardPoints, int k) {
        int windowSum=0;
        int n=cardPoints.size();
        for(int i=n-k;i<n;i++)
            windowSum+=cardPoints[i];
        int ans=windowSum;
        for(int i=0;i<k;i++){
            cout<<windowSum<<endl;
            windowSum=windowSum+cardPoints[i]-cardPoints[n-k+i];
            ans=max(ans,windowSum);
        }
        return ans;
    }
};