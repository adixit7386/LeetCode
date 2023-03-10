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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
       
        ListNode* curr=head->next;
        ListNode* previous=head;
        while(curr!=NULL){
            if(curr->val!=previous->val){
                previous->next=curr;
                previous=previous->next;
            }
            curr=curr->next;
            
        }
        previous->next=NULL;
        return head;
        
    }
};