class Solution {
public:
    int ceils(vector<int> &arr,int start,int end,int key){
        int ans=end+1;
        while(start<=end){
            int mid=(start+end)/2;
            if(arr[mid]>key){
                ans=mid;
                end=mid-1;
            }else if(arr[mid]<key){
                start=mid+1;
            }else{
                return mid;
            }
        }
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n);
        int count=0;
        arr[0]=nums[0];
        count=1;
        for(int i=1;i<n;i++){
            if(nums[i]>arr[count-1])
                arr[count++]=nums[i];
            else {
                int var=ceils(arr,0,count-1,nums[i]);
                // cout<<var<<endl;
                arr[var]=nums[i];
                }
        }
        return count;
    }
};