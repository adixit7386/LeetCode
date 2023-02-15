class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        
        
        int start=0;
        int end=arr.size()-1;
        int n=arr.size();
        if(arr.size()==1){
            return 0;
        }
        if(arr.size()==2){
            if(arr[0]>arr[1]){
                return 0;
            }else if(arr[0]<arr[1]){
                return 1;
            }
            return -1;
        }
        while(start<=end){
            
            int mid=(start+end)/2;
            
                if((mid==0||arr[mid]>=arr[mid-1])&&(mid==n-1||arr[mid]>=arr[mid+1])){
                    
                    return mid;
                    
                } if(mid>0&&arr[mid]<=arr[mid-1]){
                   end=mid-1;
                }else {
                  start=mid+1;
                }
        }
        return -1;
//         int n=arr.size();
//         int low = 0, high = n - 1;

// 		while(low <= high)
// 		{
// 			int mid = (low + high) / 2;

// 			if((mid == 0 || arr[mid - 1] <= arr[mid]) &&
// 				(mid == n - 1 || arr[mid + 1] <= arr[mid]))
// 				return mid;
// 			if(mid > 0 && arr[mid - 1] >= arr[mid])
// 				high = mid -1;
// 			else
// 				low = mid + 1;
// 		}
// 	return -1;
    }
};