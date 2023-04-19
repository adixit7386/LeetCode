class NumArray {
public:
    vector<int> sTree;
    int size;
    vector<int> nums2;
    int fillSTree(vector<int> &nums,int start,int end,int index){
        
        if(start==end){
            sTree[index]=nums[start];
            return sTree[index];
        }
        if(start>end){
            return 0;
        }
        int mid=(start+end)/2;
                      sTree[index]=fillSTree(nums,start,mid,2*index+1)+fillSTree(nums,mid+1,end,2*index+2);
        
        return sTree[index];
        
    }
    NumArray(vector<int>& nums) {
        nums2=nums;
        size=nums.size();
        sTree.resize(nums.size()*4,0);
        fillSTree(nums,0,nums.size()-1,0);
        for(int i=0;i<sTree.size();i++){
            cout<<sTree[i]<<" ";
        }
    }
    void updateTree(int ss,int se,int index,int qindex,int diff){
        if(qindex>se || ss>qindex){
            return;
        }
        if(ss>se){
            return;
        }
        
        sTree[index]+=diff;
        
        int mid=(ss+se)/2;
        if(ss==se){
            return;
        }
        updateTree(ss,mid,2*index+1,qindex,diff);
        updateTree(mid+1,se,2*index+2,qindex,diff);
    }
    void update(int index, int val) {
       int diff=val-nums2[index];
        // int diff=0;
        nums2[index]=val;
        updateTree(0,size-1,0,index,diff);
        return;
    }
    
    int findRange(int ss,int se,int qs,int qe,int index){
        if(qs>se || qe<ss){
            return 0;
        }
        if(qs<=ss && qe>=se){
            return sTree[index];
        }
        int mid=(ss+se)/2;
        return findRange(ss,mid,qs,qe,2*index+1)+findRange(mid+1,se,qs,qe,2*index+2);
        
    }
    
    int sumRange(int left, int right) {
        return findRange(0,size-1,left,right,0);
        
        return 0;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */