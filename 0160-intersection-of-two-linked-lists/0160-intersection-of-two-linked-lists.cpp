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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL){
            return NULL;
        }
        long long lengthA=0;
        ListNode* currA=headA;
        while(currA!=NULL){
            lengthA++;
            currA=currA->next;
        }
        long long lengthB=0;
        ListNode* currB=headB;
        while(currB!=NULL){
            lengthB++;
            currB=currB->next;
        }
        int diff=0;
        currA=headA;
        currB=headB;
        if(lengthA>=lengthB){
            diff=lengthA-lengthB;
            
            while(diff--){
               currA=currA->next; 
            }
            
        }else{
            diff=lengthB-lengthA;
            while(diff--){
                currB=currB->next;
            }
            
        }
        if(currA==currB){
            return currA;
        }
        while(currA->next!=currB->next){
            currA=currA->next;
            currB=currB->next;
        }
        
        return currA->next;
        
    }
};