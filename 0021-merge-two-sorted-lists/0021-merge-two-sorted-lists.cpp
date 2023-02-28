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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL&&list2==NULL){
            return NULL;
        }
        ListNode *head1 = list1;
    ListNode *head2 = list2;
    ListNode *curr = NULL;
    ListNode *listHead;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->val <= head2->val)
        {
            if (curr == NULL)
            {
                curr = head1;
                listHead = head1;
            }
            else
            {
                curr->next = head1;
                curr = curr->next;
            }
            head1 = head1->next;
        }
        else
        {
            if (curr == NULL)
            {
                curr = head2;
                listHead = head2;
            }
            else
            {
                curr->next = head2;
                curr = curr->next;
            }
            head2 = head2->next;
        }
    }

    while (head1 != NULL)
    {
        if (curr == NULL)
        {
            curr = head1;
            listHead=head1;
        }
        else
        {
            curr->next = head1;
                curr = curr->next;
        }
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        if (curr == NULL)
        {
            curr = head2;
            listHead=head2;
        }
        else
        {
           curr->next = head2;
                curr = curr->next;
        }
        head2 = head2->next;
    }
    return listHead;
        
    }
};