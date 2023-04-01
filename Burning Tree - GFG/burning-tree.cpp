//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void storeParent(Node* root,Node* parent,unordered_map<Node*,Node*>& maps){
        if(root==NULL){
            return;
        }
        maps[root]=parent;
        storeParent(root->left,root,maps);
        storeParent(root->right,root,maps);
        
    }
    int countBurningTime(Node* source,unordered_map<Node*,Node*> maps){
        unordered_map<Node*,bool> vis;
        for(auto el:maps){
            vis[el.first]=false;
        }
        queue<Node*> q;
        q.push(source);
        vis[source]=true;
        q.push(NULL);
        int count=0;
        while(q.size()>1){
            Node* temp=q.front();
            q.pop();
            if(temp==NULL){
                count++;
                q.push(temp);
            }else{
                if(maps[temp]!=NULL && vis[maps[temp]]==false){
                    q.push(maps[temp]);
                    vis[maps[temp]]=true;
                }
                if(temp->left!=NULL && vis[temp->left]==false){
                    q.push(temp->left);
                    vis[temp->left]=true;
                }
                if(temp->right!=NULL && vis[temp->right]==false){
                    q.push(temp->right);
                    vis[temp->right]=true;
                }
            }
            
        }
        return count;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*,Node*> parent;
        storeParent(root,NULL,parent);
        Node* startRoot=NULL;
        for(auto el:parent){
            if(el.first->data==target){
                startRoot=el.first;
            }
        }
        return countBurningTime(startRoot,parent);
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends