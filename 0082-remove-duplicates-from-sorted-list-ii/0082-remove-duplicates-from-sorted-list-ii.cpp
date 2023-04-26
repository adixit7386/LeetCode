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
    ListNode* deleteNodes(ListNode* head,int val){
        ListNode* curr=head;
        while(curr!=NULL && curr->val==val){
            ListNode* temp=curr;
            curr=curr->next;
            delete(temp);
        }
        return curr;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        // if(head->val==head->next->val){
        //     head=deleteNodes(head,head->val);
        //     deleteDuplicates(head);
        //     return head;
        // }else
        //     head->next=deleteDuplicates(head->next);
        // return head;
        
        ListNode* curr=head;
        ListNode* currStart=NULL;
        ListNode* prev=NULL;
        while(curr!=NULL && curr->next!=NULL){
            cout<<curr->val<<endl;
            if(curr->val == curr->next->val){
                curr=deleteNodes(curr,curr->val);
                if(prev!=NULL)prev->next=curr;
                // curr=curr->next;
            }else{
                if(currStart==NULL){
                    currStart=curr;
                }
                prev=curr;
                curr=curr->next;
            }
            
        }
        if(currStart==NULL)return curr;
        
        return currStart;
        // return deleteNodes(head,head->val);
    
    }
};