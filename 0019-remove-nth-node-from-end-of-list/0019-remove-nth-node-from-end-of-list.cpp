/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int length=0;
    ListNode* prevs=NULL;
    ListNode* next=NULL;
    void updateNodes(ListNode* head ,ListNode* prev,int counter,int n){
        if(head==NULL){
            length=counter-1;
            return;
        }
        updateNodes(head->next,head,counter+1,n);
        if(counter== length-n+1){
            prevs=prev;
            next=head->next;
        }
        return;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)return head;
        if(head->next==NULL){
            delete(head);
           
return NULL;
        }
        updateNodes(head,NULL,1,n);
        if(length==n){
            ListNode* temp=head->next;
            
            delete(head);
                return temp;
        }
        ListNode* temp=prevs->next;
        delete(temp);
        prevs->next=next;
        return head;
    }
};