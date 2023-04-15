/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        Node* prev=NULL;
        Node* child;
        while(q.size()>1){
            child=q.front();
            q.pop();
            if(child==NULL){
                q.push(NULL);
                if(prev!=NULL){
                    prev->next=child;
                }
                prev=child;
                continue;
            }
            else{
                if(prev!=NULL){
                    prev->next=child;
                }
                if(child->left!=NULL){
                    q.push(child->left);
                }
                if(child->right!=NULL){
                    q.push(child->right);
                }
                prev=child;
            }
            
            
        }
        if(prev!=NULL){
                    prev->next=NULL;
        }
        return root;
    }
};