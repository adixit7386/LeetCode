class NumArray {
public:
    vector<int> sTree;
    int size;
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
        size=nums.size();
        sTree.resize(nums.size()*4,0);
        fillSTree(nums,0,nums.size()-1,0);
        for(int i=0;i<sTree.size();i++){
            cout<<sTree[i]<<" ";
        }
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
 * NumArray* obj= new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */