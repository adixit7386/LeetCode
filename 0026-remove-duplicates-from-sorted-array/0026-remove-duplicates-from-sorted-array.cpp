class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int start=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]!=arr[start]){
                arr[++start]=arr[i];
            }
        }
        
        return start+1;
    }
};