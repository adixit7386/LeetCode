class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> afRows;
        unordered_set<int> afCols;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    afRows.insert(i);
                    afCols.insert(j);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(afRows.find(i)!=afRows.end() || afCols.find(j)!=afCols.end()){
                    matrix[i][j]=0;
                }
            }
        }
        
    }
};