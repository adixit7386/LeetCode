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
    bool validity(TreeNode* root,long long min,long long max){
        if(root==NULL){
            return true;
        }
        long long val=root->val;
        if(val<=min||val>=max){
            return false;
        }
        return validity(root->left,min,root->val)&&validity(root->right,root->val,max);
    }
    bool isValidBST(TreeNode* root) {
        long long min=-2147483649;
        long long max=2147483648;
        return validity(root,min,max);
    }
};