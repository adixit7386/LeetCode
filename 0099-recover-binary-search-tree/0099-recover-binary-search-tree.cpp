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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* first=NULL;
        TreeNode* second;
        TreeNode* prev=NULL;
        while(curr!=NULL || !st.empty()){
            while(curr!=NULL){

                st.push(curr);
                // prev = curr;
                curr = curr->left;

            }
            curr = st.top();
            st.pop();
            int prevVal = prev==NULL?INT_MIN:prev->val;
            if(prevVal>curr->val){
                if(first==NULL)
                first = prev;
                second=curr;
            }
            // cout<<curr->val<<" ";
            prev = curr;
            curr = curr->right;
        }
        swap(first->val,second->val);
    }
};