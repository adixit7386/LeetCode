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
    int getLength(ListNode* head){
        ListNode* curr=head;
        int count=0;
        while(curr!=NULL){
            count++;
            curr=curr->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int length1=getLength(headA);
        int length2=getLength(headB);
        int diff=abs(length1-length2);
        if(length1>length2){
            while(diff--){
                headA=headA->next;
            }
        }else{
            while(diff--){
                headB=headB->next;
            }
        }
        if(headA==headB) return headA;
        while(headA->next!=headB->next){
            headA=headA->next;
            headB=headB->next;
        }
        return headA->next;
    }
};