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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL)return NULL;
        ListNode* firstEnd=NULL;
        ListNode* firstStart=NULL;
        ListNode* secondEnd=NULL;
        ListNode* secondStart=NULL;
        
        ListNode* curr=head;
        while(curr!=NULL){
            if(curr->val<x){
                if(firstEnd==NULL){
                    firstEnd=curr;
                    firstStart=curr;
                }else{
                    firstEnd->next=curr;
                    firstEnd=firstEnd->next;
                }
            }else{
                if(secondEnd==NULL){
                    secondEnd=curr;
                    secondStart=curr;
                }else{
                    secondEnd->next=curr;
                    secondEnd=secondEnd->next;
                }
            }
            curr=curr->next;
        }
        if(firstEnd==NULL){
            secondEnd->next=NULL;
            return secondStart;
        }else if(secondEnd==NULL){
            firstEnd->next=NULL;
            return firstStart;
        }else{
            firstEnd->next=secondStart;
            secondEnd->next=NULL;
            return firstStart;
        }
    }
};