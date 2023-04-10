class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int> mp;
        int count=0;
        for(auto vec:equations){
            string str1=vec[0];
            string str2=vec[1];
            if(mp.find(str1)==mp.end()){
                mp[str1]=count++;
            }
            if(mp.find(str2)==mp.end()){
                mp[str2]=count++;
            }
        }
        int n=mp.size();
        vector<vector<double>> matrix(n,vector<double> (n,-1));
        
        for(int i=0;i<equations.size();i++){
            
            matrix[mp[equations[i][0]]][mp[equations[i][1]]]=values[i];
            matrix[mp[equations[i][1]]][mp[equations[i][0]]]=1/values[i];
        }
        for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	               if(matrix[i][k]==-1 || matrix[k][j]==-1){
	                   
	               }else{
	                   if(matrix[i][j]==-1){
	                       matrix[i][j]=matrix[k][j]*matrix[i][k];
	                   }else{
	                       matrix[i][j]=min(matrix[i][j],matrix[i][k]*matrix[k][j]);
	                   }
	               }
	            }
	        }
	    }
        
                                      for(int i=0;i<n;i++){
                                          for(int j=0;j<n;j++){
                                              cout<<matrix[i][j]<<" ";
                                          }
                                          cout<<endl;
                                      }
                                       
                                       
                                       
        
        vector<double> ans={};
        for(auto que:queries){
            if(mp.find(que[0])==mp.end() || mp.find(que[1])==mp.end()){
                ans.push_back(-1);
            }else
            ans.push_back(matrix[mp[que[0]]][mp[que[1]]] );
            
        }
        
                                       return ans;
    }
};