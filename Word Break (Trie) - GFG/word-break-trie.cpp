//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Trie
{
public:
    Trie *children[26];
    bool isEnd;

    Trie()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }

    void insert(string s, Trie *root)
    {
        Trie *curr = root;

        int n = s.length();
        for (auto ch : s)
        {
            int index = ch - 'a';
            if (curr->children[index] == NULL)
            {
                curr->children[index] = new Trie();
            }

            curr = curr->children[index];
        }
        curr->isEnd = true;
    }

    bool search(string s, Trie *root)
    {
        Trie *curr = root;

        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            int index = s[i] - 'a';

            if (curr->children[index] == NULL)
            {
                return false;
            }
            curr = curr->children[index];
        }
        return curr->isEnd;
    }
    bool isEmpty(Trie *root)
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
            {
                return false;
            }
        }
        return true;
    }
    Trie *deleteKey(string s, Trie *root, int i)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (i == s.length())
        {
            root->isEnd = false;

            if (isEmpty(root) == true)
            {
                delete (root);
                root = NULL;
            }
            return root;
        }
        int index = s[i] - 'a';
        root->children[index] = deleteKey(s, root->children[index], i + 1);

        if (root->isEnd == false && isEmpty(root) == true)
        {
            delete (root);
            root = NULL;
        }
        return root;
    }
};
bool CheckWord(string key,int start,Trie* tr){
    if(start>=key.length()){
        return true;
    } 
    for(int k=start+1;k<=key.length();k++){
        if(tr->search(key.substr(start,k-start),tr)){
            if(CheckWord(key,k,tr)==true){
                return true;
            }
        }
    }
    return false;
}
class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        Trie* tr=new Trie();
        for(string word:B){
            tr->insert(word,tr);
            // cout<<tr->search(word,tr)<<endl;
        }
        return CheckWord(A,0,tr);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends