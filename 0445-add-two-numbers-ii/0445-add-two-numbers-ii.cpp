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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        if(head==NULL || head->next==NULL)return head;
        ListNode* next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* list1=reverseList(l1);
        ListNode* list2=reverseList(l2);
        int ans=0;
        int carry=0;
        ListNode* head=NULL;
        ListNode* headStart=NULL;
        while(list1!=NULL && list2!=NULL){
            int currSum= list1->val + list2->val + carry;
            // ans= ans*10 + (currSum%10);
            if(head==NULL){
                head=new ListNode(currSum%10);
                headStart=head;
            }
            else {
                head->next=new ListNode(currSum%10);
                head=head->next;
            }
            carry=currSum/10;
            list1=list1->next;
            list2=list2->next;
        }
        while(list1!=NULL){
            int currSum=list1->val+carry;
            // ans= ans*10 + (currSum%10);
            if(head==NULL){
                
                head=new ListNode(currSum%10);
                headStart=head;
            }
            else {head->next=new ListNode(currSum%10);
                 head=head->next;}
            carry=currSum/10;
            list1=list1->next;
        }
        while(list2!=NULL){
            int currSum=list2->val+carry;
            if(head==NULL){head=new ListNode(currSum%10);
                          headStart=head;}
            else {head->next=new ListNode(currSum%10);
                 head=head->next;}
            // ans= ans*10 + (currSum%10);
            carry=currSum/10;
            list2=list2->next;
        }
        if(carry!=0){
            head->next= new ListNode(carry);
        }
        return reverseList(headStart);
        
    }
};