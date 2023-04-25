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
    bool even=false;
    int count=0;
    ListNode* reorder(ListNode* head,int idx){
        if(idx==(count+1)/2){
            if(even){
                ListNode* temp=head->next->next;
                head->next->next=NULL;
                return temp;
            }else{
                ListNode* temp=head->next;
                head->next=NULL;
                return temp;
            }
        }
        ListNode* newNode=reorder(head->next,idx+1);
        // if(prev!=NULL)
        // prev->next=newNode;
        ListNode* temp=newNode->next;
        // newNode->next=head;
        ListNode* temp1=head->next;
        head->next=newNode;
        newNode->next=temp1;
        return temp;
        
    }
    void reorderList(ListNode* head) {
       if(head==NULL || head->next==NULL)return;
        ListNode* curr=head;
        while(curr!=NULL){
            count++;
            curr=curr->next;
        }
        
        if((count)%2==0) even=true;
        
        reorder(head,1);
    }
};