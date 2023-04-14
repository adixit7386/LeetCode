//{ Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include <iostream>
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

int key=0;
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key);

 void insert(struct Node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->key==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new Node(n2);
                    break;
          case 'R': root->right=new Node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct Node *root=NULL;
    Node *pre=NULL;
    Node *suc=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new Node(n1);
            switch(lr){
                    case 'L': root->left=new Node(n2);
                    break;
                    case 'R': root->right=new Node(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
   // Inorder(root);
    //Node * target =ptr;
    //printkdistanceNode(root, target, k);
    //cout<<endl;
    cin>>key;
    findPreSuc(root, pre, suc, key);
	if (pre != NULL)
	cout << pre->key;
	else
	cout << "-1";

	if (suc != NULL)
	cout <<" "<<suc->key<<endl;
	else
	cout << " "<<"-1"<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
#include<bits/stdc++.h>
// void inorder(Node* root,map<int,Node*> &mp){
//     if(root==NULL){
//         return;
//     }
//     inorder(root->left,mp);
//     mp[root->key]=root;
//     inorder(root->right,mp);
// }
void inorder(Node* root,Node* &pre,Node* &suc,int key){
    if(root==NULL){
        return;
    }
    inorder(root->left,pre,suc,key);
    if(root->key<key){
        pre=root;
    }
    if(root->key>key){
        if(suc==NULL){
            suc=root;
        }
    }
    inorder(root->right,pre,suc,key);
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

// Your code goes here
    // if(root==NULL){
    //     return ;
    // }
    // if(root->key>=key){
    //     Node* curr=root;
    //     curr=curr->left;
    //     if(curr!=NULL){
    //         while(curr->right!=NULL){
    //             curr=curr->right;
    //         }
    //     }
    //     pre=curr;
    // }
    // if(root->key<=key){
    //     Node* curr=root;
    //     curr=curr->right;
    //     if(curr!=NULL){
    //         while(curr->left!=NULL){
    //         curr=curr->left;
    //         }
    //     }
    //     suc=curr;
    //     return;
    // }
    // findPreSuc(root->left,pre,suc,key);
    // findPreSuc(root->right,pre,suc,key);
    // map<int,Node*> mp;
    // inorder(root,mp);
    // pre=NULL;
    // suc=NULL;
    // for(auto it:mp){
    //     if(it.first==key){
            
    //     }else if(it.first<key){
    //         pre=it.second;
    //     }else{
    //         if(suc==NULL)
    //         suc=it.second;
    //     }
    // }
    pre=NULL;
    suc=NULL;
    inorder(root,pre,suc,key);

}