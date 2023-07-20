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
    TreeNode* firstNode=NULL;
    TreeNode* secondNode=NULL;
    TreeNode* prev=NULL;
    void preorder(TreeNode* root){
        if(root==NULL)return;
        preorder(root->left);
        // if(prev==NULL)return;
        if(prev!=NULL && root->val<prev->val){
            if(firstNode==NULL)
            firstNode=prev;
            secondNode=root;
        }
        
            
        prev=root;
        preorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        preorder(root);
        // if(firstNode==NULL || secondNode==NULL)return;
        swap(firstNode->val,secondNode->val);
        return;
    }
};