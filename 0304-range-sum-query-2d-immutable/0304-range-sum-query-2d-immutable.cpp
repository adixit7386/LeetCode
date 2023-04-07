
class NumMatrix {
public:
    vector<vector<int>> matrixs;
    NumMatrix(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                matrix[i][j]+=matrix[i-1][j];
                
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                matrix[i][j]+=matrix[i][j-1];
                
            }
        }
        matrixs=matrix;
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // vector<vector<int>> matrixs=this->mat;
        int ans=0;
        int minRow=min(row1,row2);
        int maxRow=max(row1,row2);
        int minCol=min(col1,col2);
        int maxCol=max(col1,col2);
    
        int prevB=minCol>0?matrixs[maxRow][minCol-1]:0;
        int prevT=minRow>0?matrixs[minRow-1][maxCol]:0;
        int prevP=minRow>0&&minCol>0?matrixs[minRow-1][minCol-1]:0;
        ans=matrixs[maxRow][maxCol]-prevB-prevT+prevP;
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */