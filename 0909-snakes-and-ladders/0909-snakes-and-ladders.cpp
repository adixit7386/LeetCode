class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<int> q;
        int n=board.size();
        if(n*n<=6){
            return 1;
        }
        vector<int> arr((n*n)+1,-1);
        
        vector<bool> vis((n*n)+1,false);
        // int idx=0;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         arr[i*n+j+1]=board[i][j];
        //         // cout<<arr[i*n+j]<<" ";
        //     }
        // }
        int idx=1;
        int row=n-1;
        bool flag=true;
        while(row>=0 ){
            int col;
            if(flag==false){
                col=n-1;
                while(col>=0){
                    arr[idx++]=board[row][col];
                    col--;
                }
            }else{
                col=0;
                while(col<n){
                    arr[idx++]=board[row][col];
                    col++;
                }
            }
            row--;
            flag=!flag;
            
        }
        for(int i=1;i<=n*n;i++) cout<<arr[i]<<" ";
        q.push(1);
        q.push(-1);
        int top=-2;
        int count=0;
        vis[1]=true;
        cout<<endl;
        while(q.empty()==false && count<=n*n ){
            int top=q.front();
            q.pop();
            if(top>=n*n){
                return count;
            }
            if(top==-1){
                count++;
                q.push(-1);
            }else{
                for(int i=1;i<=6;i++){
                    if(top+i<=n*n){
                        cout<<"size"<<vis[top+i]<<endl;
                        
                        cout<<"index"<<top+i<<endl;
                       
                        
                        if(arr[top+i]==-1){
                            if(!vis[top+i]){
                            vis[top+i]=true;
                            q.push(top+i);
                            }
                        }else
                        {
                            if(vis[arr[top+i]]==false){
                            q.push(arr[top+i]);
                            // cout<<vis.size()<<endl;
                            // cout<<arr[top+i]<<endl;
                            vis[arr[top+i]]=true;
                            }
                            // q.push(top+i);
                        }
                    }else{
                        // return count;
                        q.push(top+i);
                        // vis[top+i]=true;
                    }

                }
                
            }
        }
        if(count>n*n){
            return -1;
        }
        return count;
    }
};