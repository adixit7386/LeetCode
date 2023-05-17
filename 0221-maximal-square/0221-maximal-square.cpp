class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrics) {
        int n=matrics.size();
        int m=matrics[0].size();
        vector<vector<int>> matrix(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[i][j]=matrics[i][j]=='0'?0:1;
            }
        }
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==1)
                matrix[i][j]+=min({matrix[i-1][j],matrix[i][j-1],matrix[i-1][j-1]});
       
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // matrix[i][j]+=min({matrix[i-1][j],matrix[i][j-1],matrix[i-1][j-1]});
                
                ans=max(ans,matrix[i][j]*matrix[i][j]);
            }
        }
            return ans;    
    }
};