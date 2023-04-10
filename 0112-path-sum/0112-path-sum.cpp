/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void isSum(TreeNode* root,int targetSum,bool &flag,int sum){
        if(root==NULL){
            // if(targetSum==sum){
            //     flag=true;
            // }
            return;
        }
        if(root->left==NULL && root->right==NULL){
             if(targetSum==root->val+sum){
                flag=true;
                return ;
            }   
        }
        
        isSum(root->left,targetSum,flag,sum+root->val);
        
        isSum(root->right,targetSum,flag,sum+root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        bool flag=false;
        
        isSum(root,targetSum,flag,0);
        return flag;
    }
};