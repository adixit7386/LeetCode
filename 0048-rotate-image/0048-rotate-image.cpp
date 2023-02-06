class Solution {
public:
    void transpose(vector<vector<int>>& matrix){
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    void reverseColumn(vector<int>& column){
        int n=column.size();
        
        for(int i=0;i<n/2;i++){
            swap(column[i],column[n-i-1]);
            
        }
        return ;
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        int n=matrix.size();
        for(int i=0;i<n;i++){
            reverseColumn(matrix[i]);
        }
        
        return;
    }
};