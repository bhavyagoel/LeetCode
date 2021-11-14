class CombinationIterator {
public:
    
    vector<string> array; 
    int ptr = 0; 
    void helper(string &characters, string &temp, int index, int len) {
        
        if(temp.length() == len) array.push_back(temp);
        
        for(int i = index; i < characters.length(); i++) {
            temp += characters[i];
            helper(characters, temp, i+1, len);
            temp.pop_back(); 
        }
        
    }
    CombinationIterator(string characters, int combinationLength) {
        string temp = "";
        helper(characters, temp, 0, combinationLength);
        
        // sort(array.begin(), array.end());
    }
    
    string next() {
        return array[ptr++];
    }
    
    bool hasNext() {
        if(ptr < array.size()) return true; 
        return false; 
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */