class WordDictionary {
public:
    bool isEnd;
    vector<WordDictionary*> children;
    WordDictionary() {
        isEnd=false;
        children.resize(26,NULL);
    }
    
    void addWord(string word) {
        WordDictionary* curr=this;
        for(int i=0;i<word.length();i++){
            int index=word[i]-'a';
            if(curr->children[index]==NULL){
                curr->children[index]=new WordDictionary();
            }
            curr=curr->children[index];
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
        WordDictionary* curr=this;
        for(int i=0;i<word.length();i++){
            if(word[i]=='.'){
                for(int j=0;j<26;j++){
                    if(curr->children[j]!=NULL){
                        if(i==word.size()-1){
                            if(curr->children[j]->isEnd==true) return true;
                            continue;
                        }
                        if(curr->children[j]->search(word.substr(i+1,word.size()-i-1))){
                                return true;
                        }
                    }
                }
                return false;
            }else{
               int index=word[i]-'a';
                if(curr->children[index]==NULL){
                    return false;
                }
                curr=curr->children[index]; 
            }
            
        }
        return curr->isEnd==true;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */