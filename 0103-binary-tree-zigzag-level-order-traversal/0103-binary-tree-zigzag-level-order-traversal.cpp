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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        
        vector<int> subans;
       
        
        stack<TreeNode*> st1,st2;
         st1.push(root);
        while(st1.empty()==false || st2.empty()==false){
            while(st1.empty()==false){
                TreeNode* temp=st1.top();
                subans.push_back(temp->val);
                st1.pop();
                if(temp->left!=NULL){
                    st2.push(temp->left);
                }
                if(temp->right!=NULL){
                    st2.push(temp->right);
                }
                
                
                
            }
            if(subans.size()!=0){
                ans.push_back(subans);
                subans.clear();
            }
            while(st2.empty()==false){
                TreeNode* temp=st2.top();
                subans.push_back(temp->val);
                st2.pop();
                
                if(temp->right!=NULL){
                    st1.push(temp->right);
                }
                if(temp->left!=NULL){
                    st1.push(temp->left);
                }
                
            }
            if(subans.size()!=0){
                ans.push_back(subans);
                subans.clear();
            }
        }
        return ans;
        
        
        
    }
};