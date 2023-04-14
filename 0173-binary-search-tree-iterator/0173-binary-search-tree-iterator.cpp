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
class BSTIterator {
public:
    unordered_map<TreeNode*,TreeNode*> mp;
    vector<TreeNode*> trav;
    TreeNode* curr;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        trav.push_back(root);
        inorder(root->right);
        
    }
    
    BSTIterator(TreeNode* root) {
        
        inorder(root);
        int n=trav.size();
        curr=trav[0];
        for(int i=0;i<n-1;i++){
            mp[trav[i]]=trav[i+1];
        }
        mp[trav[n-1]]=NULL;
    }
    
    int next() {
        TreeNode* t=curr;
        // if(mp[t]==NULL) return -1;
        curr=mp[curr];
        
        return t->val;
        // if(mp[curr]!=NULL){
        //     int ans=mp[curr]->val;
        //         curr=mp[curr];
        //     return ans;
        // }
        // curr=mp[curr];
        // return -1;
    }
    
    bool hasNext() {
        if(curr==NULL){
            return false;
        }
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */