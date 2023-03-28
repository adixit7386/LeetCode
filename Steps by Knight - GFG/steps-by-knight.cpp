//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool isvalid(int i,int j){
        if(i==0||j==0){
            return false;
        }
        if(abs(abs(i)-abs(j))==1){
            return true;
        }
        return false;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&targetPos,int n)
	{
	    // Code here
	    vector<vector<int>> grid(n+1,vector<int> (n+1,0));
	    grid[targetPos[0]][targetPos[1]]=1;
	   
	    if(targetPos[0]==KnightPos[0]&&targetPos[1]==KnightPos[1]){
	        return 0;
	    }
        int count=1;
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n+1,vector<int> (n+1,false));
       
        q.push({KnightPos[0],KnightPos[1]});
        q.push({-1,-1});
        
        vis[KnightPos[0]][KnightPos[1]]=true;
       
        
        
        while(q.size()>1){
            pair<int,int> currPt=q.front();
            q.pop();
            
            if(currPt.first==-1){
                count++;
                q.push({-1,-1});
            }else{
                for(int i=-2;i<=2;i++){
                for(int j=-2;j<=2;j++){
                    if(isvalid(i,j)){
                        int x=currPt.first+i;
                        int y=currPt.second+j;
                        // cout<<grid[x][y]<<" "<<checkx<<endl;
                        
                        if(x>=1&&x<=n&&y>=1&&y<=n&&vis[x][y]==false){
                            if(targetPos[0]==x&&targetPos[1]==y)
                            return count;
                            
                            vis[x][y]=true;
                            // cout<<x<<y<<endl;
                            q.push({x,y});
                        }
                    }
                }
            }
            }
            
            
          
        }
        return -1;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends