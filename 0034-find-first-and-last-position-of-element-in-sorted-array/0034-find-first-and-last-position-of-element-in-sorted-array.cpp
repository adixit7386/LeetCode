class Solution {
public:
    int firstOcc(vector<int> &nums,int key){
        int start=0;
        int end=nums.size()-1;
        
        while(start<=end){
            int mid=(start+end)/2;
            
            if(nums[mid]==key){
                if(mid>0 && nums[mid]==nums[mid-1]){
                    end=mid-1;
                }else{
                    return mid;
                }
            }else if(nums[mid]>key){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return -1;
    }
    int lastOcc(vector<int> &nums,int key){
        int start=0;
        int end=nums.size()-1;
        
        while(start<=end){
            int mid=(start+end)/2;
            
            if(nums[mid]==key){
                if(mid<end && nums[mid]==nums[mid+1]){
                    start=mid+1;
                }else{
                    return mid;
                }
            }else if(nums[mid]>key){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int a=firstOcc(nums,target);
        int b=lastOcc(nums,target);
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};