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
        ListNode* curr=head;
        int count=0;
        while(curr!=NULL){
            count++;
            curr=curr->next;
        }
        return count;
    }
    int getDecimalValue(ListNode* head) {
        int length=getLength(head);
        int multiplier=pow(2,length-1);
        int ans=0;
        while(head!=NULL){
            ans+= multiplier*head->val;
            
            head=head->next;
            multiplier/=2;
        }
        return ans;
    }
};