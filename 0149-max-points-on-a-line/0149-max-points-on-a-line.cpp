class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==1){
            return 1;
        }
        int count =2;
        int ans=2;
        for(int i=0;i<points.size()-2;i++){
            for(int j=i+1;j<points.size();j++){
                float slope;
                if(points[i][0]==points[j][0]){
                    slope=INT_MAX;
                }else
                    slope=((float)(points[i][1]-points[j][1])/(points[i][0]-points[j][0]));
                count=2;
                for(int k=j+1;k<points.size();k++){
                    
                    float second_slope;
                if(points[i][0]==points[k][0]){
                    second_slope=INT_MAX;
                }else
                    second_slope=((float)(points[i][1]-points[k][1])/(points[i][0]-points[k][0]));
                    
                    if(slope==second_slope){
                        count++;
                    }
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};