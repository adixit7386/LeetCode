/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        if(head->next==NULL){
            return false;
        }
        ListNode* slowPtr=head;
        ListNode* fastPtr=head;
        
        do{
            slowPtr=slowPtr->next;
            fastPtr=fastPtr->next->next;
        }while(fastPtr!=NULL && fastPtr->next!=NULL&&fastPtr!=slowPtr);
        return slowPtr==fastPtr;
    }
};