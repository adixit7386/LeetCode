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
    void uniquePaths(TreeNode* root,string str,vector<string> &ans){
        if(root==NULL)return;
        if(!root->left && !root->right)ans.push_back(str);
        if(root->left!=NULL)uniquePaths(root->left,str+"->"+to_string(root->left->val),ans);
        if(root->right!=NULL)uniquePaths(root->right,str+"->"+to_string(root->right->val),ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        uniquePaths(root,to_string(root->val),ans);
        return ans;
        
    }
};