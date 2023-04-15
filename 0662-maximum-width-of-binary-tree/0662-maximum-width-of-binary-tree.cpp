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
    void traversal(TreeNode* root,long long level,unordered_map<long long,pair<long long,long long>>& mp,long long index)     
    {
        if(root==NULL) return;
        if(mp.find(index)==mp.end()) mp[index]={INT_MAX,INT_MIN};
        mp[index].first=min(mp[index].first,level);
        mp[index].second=max(mp[index].second,level);
        traversal(root->left,2*level+1,mp,index+1);
        traversal(root->right,2*level+2,mp,index+1);
        
    }
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int ans=0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            int mmin = q.front().second;    // to take the id starting from zero
            int first, last;
            for(int i=0; i<size; i++){
                long long cur_id = q.front().second-mmin;
                TreeNode * node = q.front().first;
                q.pop();
                if(i==0) first = cur_id;
                if(i==size-1) last = cur_id;
                if(node->left)
                    q.push({node->left, cur_id*2+1});
                if(node->right)
                    q.push({node->right, cur_id*2+2});
            }
            ans = max(ans, last-first+1);
        }
        return ans;
     
    }
};