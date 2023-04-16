//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++

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

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        map<string,vector<string>> mp;
        for(auto str:string_list){
            string copy=str;
            sort(copy.begin(),copy.end());
            mp[copy].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto it:mp){
            vector<string> sub_ans;
            // subans.push_back(it.first);
            for(auto str:it.second){
                sub_ans.push_back(str);
            }
            ans.push_back(sub_ans);
            sub_ans.clear();
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

// } Driver Code Ends