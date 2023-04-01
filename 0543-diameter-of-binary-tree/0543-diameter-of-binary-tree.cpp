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
    int binaryTree(TreeNode* root,int &diameter){
        if(root==NULL){
            return 0;
        }
        int lh=binaryTree(root->left,diameter);
        int rh=binaryTree(root->right,diameter);
        diameter=max(diameter,1+lh+rh);
        return (1+max(lh,rh));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int global=0;
        binaryTree(root,global);
        return global-1;
    }
};