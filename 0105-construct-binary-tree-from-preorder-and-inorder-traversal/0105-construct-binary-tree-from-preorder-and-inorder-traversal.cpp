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
    int findIndex(int val,vector<int>& inorder){
       for(int i=0;i<inorder.size();i++){
           if(inorder[i]==val){
               return i;
           }
       }
        return -1;
    }
    TreeNode* buildNewTree(vector<int> preorder,int &prIndex,vector<int> inorder,int si,int ei){
        if(prIndex==preorder.size()){
            return NULL;
        }
        if(si>ei){
            return NULL;
        }
        TreeNode* node=new TreeNode(preorder[prIndex]);
        int index=findIndex(preorder[prIndex],inorder);
        prIndex++;
        
        node->left=buildNewTree(preorder,prIndex,inorder,si,index-1);
        node->right=buildNewTree(preorder,prIndex,inorder,index+1,ei);
        return node;
        
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int globals=0;
        TreeNode* root=buildNewTree(preorder,globals,inorder,0,inorder.size());
        return root;
    }
};