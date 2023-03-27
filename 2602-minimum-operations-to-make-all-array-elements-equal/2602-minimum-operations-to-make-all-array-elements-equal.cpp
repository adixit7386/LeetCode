class Solution {
public:
    long long ceilIdx(vector<int> &arr,int key){
        
        long long n=arr.size();
        // cout<<n<<endl;
        long long ans=n;
        long long start=0;
        long long end=n-1;
        while(start<=end){
            int mid =(start+end)/2;
            if(arr[mid]==key){
                return mid;
            }else if(arr[mid]<key){
                start=mid+1;
            }else {
                ans=mid;
                end=mid-1;
            }
        }
        // cout<<ans<<endl;
        return ans;
        
    }
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<long long> prefixSum(nums.size(),0);
        prefixSum[0]=nums[0];
        
        for(int i=1;i<nums.size();i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
            
            
            
            
        }
        long long n=queries.size();
        long long ans=0;
        vector<long long> answer;
        for(int i=0;i<n;i++){
            
            long long number=queries[i];
            
            long long ceilidx=ceilIdx(nums,queries[i]);
            // cout<<ceilidx<<endl;
            long long leftSum=0;
            long long rightSum=0;
            
            long long size = nums.size();
            long long leftCount=ceilidx-1;
            
            long long rightCount=nums.size()-ceilidx;
            
            if(ceilidx==0){
                ans=prefixSum[size-1]-queries[i]*size;
            }
            else if(ceilidx==size){
                ans=queries[i]*size-prefixSum[size-1];
            }
            else{
                // cout<<size<<" "<<ceilidx<<" "<<endl;
                // ans=(prefixSum[size-1]-prefixSum[ceilidx-1]-queries[i]*rightCount);
                ans=((prefixSum[size-1]-prefixSum[ceilidx-1])-(queries[i]*rightCount));
                ans+=(queries[i]*ceilidx-prefixSum[ceilidx-1]);
            }
            
            

            answer.push_back(ans);
            
        }
        return answer;
    
    }
};