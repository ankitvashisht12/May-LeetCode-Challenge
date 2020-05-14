class Trie {
    Trie* letters[26];
    bool isLeaf;
public:
    /** Initialize your data structure here. */
    Trie() {
        isLeaf = false;
        for(int i=0; i<26; i++) letters[i] = NULL;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *currPtr = this;
        for(char ch : word){
            if(!(currPtr->letters[ch - 'a'])) currPtr->letters[ch - 'a']  = new Trie;
            currPtr  = currPtr->letters[ch - 'a'];
        }
        currPtr->isLeaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *currPtr = this;
        for(char ch : word){
            if(!(currPtr->letters[ch - 'a'])) return false;
            currPtr = currPtr->letters[ch - 'a'];
        }
        
        if(currPtr->isLeaf) return true;
        else return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *currPtr = this;
        for(char ch : prefix){
            if(!(currPtr->letters[ch - 'a'])) return false;
            currPtr = currPtr->letters[ch - 'a'];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
