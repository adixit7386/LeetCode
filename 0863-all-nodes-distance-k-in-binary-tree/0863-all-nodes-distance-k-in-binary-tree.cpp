/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> arr;
    void printatk(TreeNode* root,int k){
        if(root==NULL){
            return;
        }
        if(k==0)arr.push_back(root->val);
        printatk(root->left,k-1);
        printatk(root->right,k-1);
    }
    int height(TreeNode* root,int target,int &dist,int k){
        
        if(root==NULL) return 0;
        if(root->val==target){
            printatk(root,k);
            dist=0;
            return 1;
        }
        int ldist=-1,rdist=-1;
        int left=height(root->left,target,ldist,k);
        int right=height(root->right,target,rdist,k);
        
            // cout<<root->val<<" "<<ldist<<" "<<rdist<<endl;
        
        if(rdist!=-1){
            dist=rdist+1;
            if(dist==k){
                arr.push_back(root->val);
            }
            printatk(root->left,k-dist-1);
            
        }
        else if(ldist!=-1){
            dist=ldist+1;
            if(dist==k){
                arr.push_back(root->val);
            }
            printatk(root->right,k-dist-1);
        }
        // cout<<root->val<<" "<<dist<<" "<<endl;
        return (max(left,right)+1);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        int dist=-1;
        int tar=target->val;
        height(root,tar,dist,k);
        return arr;
    }
};