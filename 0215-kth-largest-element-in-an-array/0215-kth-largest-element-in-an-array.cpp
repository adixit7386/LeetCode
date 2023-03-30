class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int,vector<int>,greater<int>> pq;
        
//         while(k--)pq.push(nums[k]);
        
//         for(int i=k;i<nums.size();i++){
//             if(nums[i]>pq.top()){
//                 pq.pop();
//                 pq.push(nums[i]);
                
                
//             }
//         }
        priority_queue<int> pq(nums.begin(),nums.end());
        
        while(k>1){
            pq.pop();
            k--;
        }
        return pq.top();
        
    }
};