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
     int getLength(ListNode* head){
        int length=0;
        while(head!=NULL){
            length++;
            head=head->next;
        }
        return length;
    }
    int getDecimalValue(ListNode* head) {
        signed int ans=0;
        ListNode* curr=head;
        int length=getLength(head);
         int mul=pow(2,length-1);
        while(curr!=NULL){
            ans+= curr->val*mul;
            
            curr=curr->next;
            mul/=2;
        }
        return ans;
       
        
        
       
    }
};