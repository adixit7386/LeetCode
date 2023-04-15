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
    int target;
    int curr;
    int ans;
    void findkthSmallest(TreeNode* root){
        if(ans!=-1){
            return;
        }
        if(root==NULL){
            return;
        }
        findkthSmallest(root->left);
        if(curr==target && ans==-1){
            // cout<<root->val<<endl;
            ans=root->val;
            return;
        }
        curr++;
        findkthSmallest(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        target=k;
        curr=1;
        ans=-1;
        findkthSmallest(root);
        return ans;
    }
};