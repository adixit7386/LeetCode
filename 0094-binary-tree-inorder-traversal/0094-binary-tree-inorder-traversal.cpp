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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        TreeNode* curr=root;
        stack<TreeNode*> st;
        // st.push(root);
        // curr=curr->left;
        while(st.empty()==false||curr!=NULL){
            
            while(curr!=NULL){
                st.push(curr);
                curr=curr->left;
                
            }
            TreeNode* temp=st.top();
            st.pop();
            ans.push_back(temp->val);
            
            if(temp->right!=NULL){
                curr=temp->right;
            }
            
        }
        return ans;
    }
};