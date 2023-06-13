class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int sr = 0, sc = 0, er = n-1,ec = n-1,x=1,i;
        vector<vector<int>> v(n,vector<int>(n));
        while(sr<=er && sc <= ec){
            for(i = sc; i <= ec && sr<=er; i++){
                v[sr][i] = x++;
            }
            sr++;
            for(i = sr; i <= er &&  sc<=ec; i++){
                v[i][ec] = x++;
            }
            ec--;
            for(i = ec; i >= sc &&  sr<=er; i--){
                v[er][i] = x++;
            }
            er--;
            for(i = er; i >= sr && sc<=ec; i--){
                v[i][sc] = x++;
            }
            sc++;
        }
        return v;
    }
};