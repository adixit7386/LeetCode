/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* duplicateNode(Node* head){
        Node* curr=head;
        while(curr!=NULL){
            Node* temp=curr->next;
            curr->next=new Node(curr->val);
            curr->next->next=temp;
            
            
            
            curr=curr->next->next;
        }
        return head;
    }
    Node* copyRandomList(Node* head) {
        Node* headStart=duplicateNode(head);
        Node* curr=headStart;
        // while(curr!=NULL){
        //     cout<<curr->val<<endl;
        //     curr=curr->next;
        // }
        while(curr!=NULL && curr->next!=NULL){
            if(curr->random==NULL){
                curr->next->random=NULL;
            }else
            curr->next->random=curr->random->next;
            curr=curr->next->next;
        }
        if(headStart==NULL)return NULL;
        
        // curr=headStart->next;
        
        
        // curr->next=NULL;
        curr=headStart;
        Node* ans=headStart->next;
        while(curr!=NULL && curr->next->next!=NULL ){
            Node* temp=curr->next->next;
            curr->next->next=curr->next->next->next;
            curr->next=temp;
            curr=curr->next;
        }
        if(curr->next->next==NULL)
        curr->next=NULL;
        
        
        return ans;
    }
};