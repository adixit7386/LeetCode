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
    ListNode* reverse(ListNode* head){
        if(head==NULL||head->next==NULL) return head;
        ListNode* temp = head->next;
        
        ListNode* newHead=reverse(head->next);
        
        temp->next=head;
        head->next=NULL;
        return newHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int temp=k;
        ListNode* curr=head;
        ListNode* prevTail=head;
        ListNode* prevHead;
        ListNode* ans;
        while(curr!=NULL && k>0){
            prevHead=curr;
            curr=curr->next;
            k--;
        }
        ans=prevHead;
        prevHead->next=NULL;
        reverse(prevTail);
        
        while(curr!=NULL){
            ListNode* nextHead;
            ListNode* nextTail=curr;
            k=temp;
            while(curr!=NULL && k>0){
                nextHead=curr;
                curr=curr->next;
                k--;
            }
            if(curr==NULL && k>0){
                prevTail->next=nextTail;
                return ans;
            }
            nextHead->next=NULL;
            reverse(nextTail);
            prevTail->next=nextHead;
            prevTail=nextTail;
            
        }
        // if(curr!=NULL && curr->next==NULL) prevTail->next = curr;
        return ans;
    }
};