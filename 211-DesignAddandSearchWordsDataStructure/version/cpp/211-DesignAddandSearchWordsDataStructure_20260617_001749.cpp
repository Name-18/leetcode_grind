// Last updated: 6/17/2026, 12:17:49 AM
class TrieNode{
    public:
        unordered_map<char, TrieNode*> child;
        int isWord = false;
};
class WordDictionary {
    TrieNode* head;
public:
    WordDictionary() {
        head = new TrieNode();
    }
    
    void addWord(string word) {
        auto tmp = head;
        for(char c: word){
            
            if (!tmp->child.contains(c)){
                tmp->child[c] = new TrieNode();
            }
            tmp = tmp->child[c];
        }
        tmp->isWord = true;
    }
    
    bool search(string word) {
        auto tmp = head;
        return search(word, 0, tmp);
    }

    bool search(string word, int idx, TrieNode* curNode){
        // cout<<word<<' '<<idx<<endl;
        if (idx == word.size()){
            return curNode != nullptr && curNode->isWord;
        }

        int c = word[idx];
        if (c == '.'){
            for(auto &[nxtC, nxtNode]: curNode->child){
                if (search(word, idx+1, nxtNode)){
                    return true;
                }
            }
            return false;
        }
        if (curNode == nullptr || !curNode->child.contains(c)){
            return false;
        }
        auto nxtNode = curNode->child[c];
        
        return search(word, idx+1, nxtNode);    
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */