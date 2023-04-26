/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL) return NULL;
        if(head->child==NULL){
            head->next=flatten(head->next);
            return head;
        }else{
            Node* temp=head->next;
            head->next=head->child;
            head->child=NULL;
            Node* temp3=flatten(head->next);
            head->next=temp3;
            if(temp3!=NULL)
            temp3->prev=head;
            Node* temp2 =head;
            
            while(temp2->next!=NULL)temp2=temp2->next;
            temp2->next=temp;
            if(temp!=NULL)
            temp->prev=temp2;
            return head;
            
        }
    }
};