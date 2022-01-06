// https://leetcode.com/problems/stream-of-characters/discuss/1610834/C%2B%2BPython-3-Simple-Solution-w-Explanation-or-Hashset-%2B-Trie-%2B-Rolling-Hash

class Trie {
    Trie* chars[26]{};
    bool endsHere = false;
    
public:    
    void insert(string& s) {                              // inserts a string in Trie
        auto cur = this;
        for(int i = size(s)-1; ~i; i--) {                 // insert in reverse order
            if(!cur -> chars[s[i]-'a'])
                cur -> chars[s[i]-'a'] = new Trie();      // add new node for current character
            cur = cur -> chars[s[i]-'a'];                 // move to that character's node
        }
        cur -> endsHere = true;                           // mark that a word ends at this node
    }
    
    bool search(string& s) {                              // searches for a suffix of string
        auto cur = this;
        for(int i = size(s)-1; ~i; i--) {
            if(!cur -> chars[s[i]-'a']) return false;     // no letter-link to next character exists
            cur = cur -> chars[s[i]-'a'];
            if(cur -> endsHere) return true;              // found a  word ending at this node => suffix of s found in Trie
        }
        return false;
    }
};

class StreamChecker {
    Trie *T = new Trie();
    string queryStream = "";
public:
    StreamChecker(vector<string>& words) {
        for(auto& w : words) T -> insert(w);
    }
    
    bool query(char c) {
        queryStream += c;                                  // add new character to query stream
        return T -> search(queryStream);                   // and search for any suffix in Trie
    }
};
/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */


/*
class StreamChecker {
private:   
    struct TrieNode {
        struct TrieNode *children[26];
        bool isEndOfWord = false;
    };
    
    void insert(struct TrieNode* root, string key) {
        struct TrieNode* pCrawl = root; 
        
        for(int i = key.length()-1; ~i ; i--) {
            int index = key[i]-'a';
            if(!pCrawl->children[index]) pCrawl->children[index] = new TrieNode();
            pCrawl = pCrawl->children[index];
        }
        pCrawl->isEndOfWord = true;
    }
    
    bool search(struct TrieNode* root, string key) {
        struct TrieNode* pCrawl = root;
        
        for(int i = key.length()-1; ~i ; i--) {
            int index = key[i]-'a';
            if(!pCrawl->children[index]) return false;
            pCrawl = pCrawl->children[index];
            if(pCrawl->isEndOfWord) return true;
        }
        return false;
    }
    
public:
    string queryString = "";
    struct TrieNode* root;
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for(auto word : words) {
            insert(root, word);
        }
    }
    
    bool query(char letter) {
        queryString += letter;
        return search(root, queryString);
    }
};
*/