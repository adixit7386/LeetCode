class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int rowStart=0,rowEnd=n-1,colStart=0,colEnd=m-1;
        vector<int> ans;
        while(rowStart<=rowEnd && colStart<=colEnd){
            // cout<<rowStart<<" "<<rowEnd<<endl;
            // cout<<colStart<<" "<<colEnd<<endl;
            

            // cout<<"hello"<<endl;
            for(int i=colStart;i<=colEnd;i++){
                ans.push_back(matrix[rowStart][i]);
            }
            rowStart++;
                if(!(rowStart<=rowEnd && colStart<=colEnd))break;
            for(int i=rowStart;i<=rowEnd;i++){
                ans.push_back(matrix[i][colEnd]);
            }
            colEnd--;
                if(!(rowStart<=rowEnd && colStart<=colEnd))break;
            for(int i=colEnd;i>=colStart;i--){
                ans.push_back(matrix[rowEnd][i]);
            }
            rowEnd--;
                if(!(rowStart<=rowEnd && colStart<=colEnd))break;
            for(int i=rowEnd;i>=rowStart;i--){
                ans.push_back(matrix[i][colStart]);
            }
            colStart++;
                if(!(rowStart<=rowEnd && colStart<=colEnd))break;
        }
        return ans;
    }
};