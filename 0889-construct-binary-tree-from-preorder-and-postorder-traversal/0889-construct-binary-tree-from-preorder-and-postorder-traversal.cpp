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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        unordered_map<int,int> premp;
        
        for(int i=0;i<n-1;i++){
            premp[preorder[i]]=preorder[i+1];
        }
        unordered_map<int,TreeNode*> nodemap;
        for(auto it:preorder){
            nodemap[it]=new TreeNode(it);
        }
        premp[preorder[n-1]]=-1;
        unordered_map<int,int> postmp;
        for(int i=1;i<n;i++){
            postmp[postorder[i]]=postorder[i-1];
        }
        postmp[postorder[0]]=-1;
        vector<bool> vis(31,false);
        TreeNode* root=NULL;
        for(int i=0;i<n;i++){
            int rootval=preorder[i];
            // if(vis[rootval]==false){
                int leftval=premp[rootval];
                int rightval=postmp[rootval];

                TreeNode* tNode=nodemap[rootval];
                if(leftval!=-1 && vis[leftval]==false){
                    tNode->left=nodemap[leftval];
                    vis[leftval]=true;
                }
                if(rightval!=-1 && vis[rightval]==false){
                    tNode->right=nodemap[rightval];
                    vis[rightval]=true;
                }
                if(root==NULL){
                    root=tNode;
                }
                vis[rootval]=true;
            // }
        }
        return root;
        
    }
};