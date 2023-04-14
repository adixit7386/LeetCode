//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        
     cout<<isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends


/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
void inorder(Node* root,vector<int> &trav,unordered_set<int> &st){
    if(root==NULL){
        return;
    }
    inorder(root->left,trav,st);
    if(!root->left and !root->right){st.insert(root->data);}
    
    trav.push_back(root->data);
    inorder(root->right,trav,st);
    
}

bool isDeadEnd(Node *root)
{
    //Your code here
    vector<int> trav;
    unordered_set<int> st1;
    inorder(root,trav,st1);
    // cout<<trav.size()<<endl;
    if(trav.size()==1){
        return false;
    }
    if(trav[0]==1 && trav[1]-trav[0]==1){
        return true;
    }
    
    for(int i=1;i<trav.size()-1;i++){
        // cout<<trav[i]<<" ";
        if(st1.find(trav[i])!=st1.end()){
            if(trav[i]-trav[i-1]==1 && trav[i+1]-trav[i]==1){
                return true;
            }
        }
        
    }
    // if(trav[trav.size()-1]-trav[trav.size()-2] ==1)
    return false;
    
}