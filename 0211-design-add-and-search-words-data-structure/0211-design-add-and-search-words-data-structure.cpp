class WordDictionary {
    bool isEnd;
    WordDictionary* children[26];

public:
    WordDictionary() {
        isEnd=false;
        
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }


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
            int index=word[i]-'a';
            if(word[i]=='.'){ 
                int k=0;
                for(k=0;k<26;k++){
                    if(curr->children[k]!=NULL){
                        if(i==word.length()-1){
                            
                            if(curr->children[k]->isEnd==true){
                                return true;
                            }
                        }
                        
                        else if(curr->children[k]->search(word.substr(i+1,word.length()-i))){
                            return true;
                        }
                    }

                }
                if(k==26){
                    return false;
                }

            }else{


                if(curr->children[index]==NULL){
                    return false;
                }
            }
            curr=curr->children[index];
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