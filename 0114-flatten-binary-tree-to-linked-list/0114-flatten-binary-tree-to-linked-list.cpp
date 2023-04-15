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
    TreeNode* prev;
    // TreeNode* head;
    void flattenTree(TreeNode* root){
        if(root==NULL){
            // if(prev==NULL){
            //     return;
            // }else{
            //     prev->right=NULL;
            // }
            return;
        }
        //work
        TreeNode* right=root->right;
        TreeNode* left=root->left;
        if(prev==NULL){
            root->left=NULL;
        }else{
            prev->right=root;
            root->left=NULL;
        }
        prev=root;
        flattenTree(left);
        flattenTree(right);
    }
    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
        prev=NULL;
        flattenTree(root);
        // prev->right=NULL;
        // while(root!=NULL){
        //     root->left=NULL;
        //     root=root->right;
        // }
        return;
            
        
    }
};