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
    
    int count=0;
    unordered_map<long,int> st;
    void findPath(TreeNode* root,long long targetSum,long long currSum){
        
        if(root==NULL)return;
        
        currSum= currSum+root->val;
        if(currSum==targetSum) count+=1;
        
        if(st.find(currSum-targetSum)!=st.end()) count+=st[currSum-targetSum];
        st[currSum]++;
        findPath(root->left,targetSum,currSum);
        findPath(root->right,targetSum,currSum);
        st[currSum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int,int> st1;
        long long curr=0;
        findPath(root,targetSum,curr);
        return count;
        
    }
};