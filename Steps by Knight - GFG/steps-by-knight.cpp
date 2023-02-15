//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&targetPos,int N)
	{
	    // Code here
	    if(N==1){
	        return 0;
	    }
	    vector<vector<bool>> vis(N+1,vector<bool> (N+1,false));
	    
	    queue<pair<int,int>> q;
	    
	    q.push({KnightPos[0],KnightPos[1]});
	    vis[KnightPos[0]][KnightPos[1]]=true;
	    int count=0;
	   
	    
	    while(q.empty()==false){
	        count++;
	        
	        int size=q.size();
	        while(size--){
	            
	        pair<int,int> pr=q.front();
	        q.pop();
	        vector<int> first={-1,-2,1,2};
	        
	       
	        for(int i=0;i<4;i++){
	            for(int j=0;j<4;j++){
	                if(abs(abs(first[i])-abs(first[j]))==1){
	                    int xval=pr.first+first[i];
	                    int yval=pr.second+first[j];
	                    if(xval==targetPos[0]&& yval==targetPos[1]){
	                        return count;
	                    }
	                    if(xval>=1&&xval<N+1&&yval>=1&&yval<N+1&&vis[xval][yval]==false){
	                        
	                        q.push({xval,yval});
	                        vis[xval][yval]=true;
	                    }
	                    
	                    
	                }
	            }
	        }
	        }
	    }
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