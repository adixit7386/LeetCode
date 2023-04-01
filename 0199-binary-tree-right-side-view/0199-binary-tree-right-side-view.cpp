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
    void rightView(TreeNode* root,int level,int &maxlevel,vector<int> &ans){
        if(root==NULL){
            return;
        }
        if(level==maxlevel){
            ans.push_back(root->val);
            maxlevel++;
        }
        rightView(root->right,level+1,maxlevel,ans);
        rightView(root->left,level+1,maxlevel,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int maxlevel=0;
        int level=0;
        rightView(root,level,maxlevel,ans);
        return ans;
    }
};