//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        
        Node* zerosHead=NULL;
        Node* zerosEnd=NULL;
        Node* onesHead=NULL;
        Node* onesEnd=NULL;
        
        Node* twosHead=NULL;
        Node* twosEnd=NULL;
        
        Node* curr=head;
        
        while(curr!=NULL){
            if(curr->data==0){
                if(zerosEnd==NULL){
                    zerosEnd=curr;
                    zerosHead=curr;
                }else{
                    zerosEnd->next=curr;
                    zerosEnd=zerosEnd->next;
                }
                
            }else if(curr->data==1){
                if(onesEnd==NULL){
                    onesEnd=curr;
                    onesHead=curr;
                }else{
                    onesEnd->next=curr;
                    onesEnd=onesEnd->next;
                }
            }else{
                if(twosEnd==NULL){
                    twosEnd=curr;
                    twosHead=curr;
                }else{
                    twosEnd->next=curr;
                    twosEnd=twosEnd->next;
                }
                
                
            }
            curr=curr->next;
            
        }
        if(twosEnd!=NULL){
            twosEnd->next=NULL;
        }
        
        if(zerosHead==NULL){
            if(onesHead==NULL){
                return twosHead;
            }else{
                onesEnd->next=twosHead;
                return onesHead;
            }
            
        }else{
            if(onesHead==NULL){
                zerosEnd->next=twosHead;
                return zerosHead;
            }else{
                zerosEnd->next=onesHead;
                onesEnd->next=twosHead;
                return zerosHead;
                
            }
        }
        
        
        
        
        
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends