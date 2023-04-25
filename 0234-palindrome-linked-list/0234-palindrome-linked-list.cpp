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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL)return NULL;
        
        ListNode* fastPtr=head->next;
        ListNode* slowPtr=head;
        
        while(fastPtr!=NULL && fastPtr->next!=NULL){
            fastPtr=fastPtr->next->next;
            slowPtr=slowPtr->next;
        }
        return slowPtr;
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)return head;
        if(head->next==NULL)return head;
        ListNode* temp=head->next;
        ListNode* newhead=reverseList(head->next);
        temp->next=head;
        head->next=NULL;
        return newhead;
    }
    bool areIdentical(ListNode* head1,ListNode* head2){
        while(head1!=NULL && head2!=NULL){
            if(head1->val !=head2->val)return false;
           head1=head1->next;
            head2=head2->next;
        }
        
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL)return true;
        if(head->next==NULL)return true;
        if(head->next->next==NULL) return head->val==head->next->val;
        // if(head->)
        ListNode* curr=head;
        ListNode* end=NULL;
            while(curr->next!=NULL){
                curr=curr->next;
            }
        ListNode* middle=middleNode(head);
        // cout<<middle->val<<endl;
        ListNode* head2=reverseList(middle->next);
        
        return areIdentical(head,head2);
     
    }
};