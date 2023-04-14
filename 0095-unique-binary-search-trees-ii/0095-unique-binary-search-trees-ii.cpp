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
    
    vector<TreeNode*> buildTree(int start,int end){
        if(start>end){
            return {NULL};
        }
        vector<TreeNode*> ans;
        for(int i=start;i<=end;i++){
            
            
            vector<TreeNode*> left=buildTree(start,i-1);
            vector<TreeNode*> right=buildTree(i+1,end);
            for(int k=0;k<left.size();k++){
                for(int j=0;j<right.size();j++){
                    TreeNode* root=new TreeNode(i);
                    root->left=left[k];
                    root->right=right[j];
                    ans.push_back(root);
                }
            }
            
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return buildTree(1,n);
    }
};