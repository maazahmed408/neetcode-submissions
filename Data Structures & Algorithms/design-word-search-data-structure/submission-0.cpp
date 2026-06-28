class Trienode {
    public :
    Trienode* children[26];
    bool endOfWord = false;

    Trienode(){
        for(int i = 0; i<26;i++){
            children[i] = nullptr;
        }
        endOfWord = false;
    }
};

class WordDictionary {
    Trienode* root;
public:
    WordDictionary() {
        root = new Trienode();
    }
    
    void addWord(string word) {
        Trienode* curr = root;
        for(char ch : word){
            int i = ch - 'a';
            if(curr->children[i] == nullptr){
                curr->children[i] = new Trienode();
            }
            curr = curr->children[i];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(word,0,root);
    }

private:
    bool dfs(string word , int j , Trienode* root){
        Trienode* curr = root;
        for(int i = j ; i < word.size() ; ++i){
            char ch = word[i];
            if(ch == '.'){
                for(Trienode* child : curr->children){
                    if(child != nullptr && dfs(word, i + 1 , child)) {return true;}
                }
                return false;
            }else{
                int idx = ch - 'a';
                if(curr->children[idx]==nullptr){
                    return false;
                }
                curr = curr->children[idx];
            }
        }
        return curr->endOfWord;
    }
};
