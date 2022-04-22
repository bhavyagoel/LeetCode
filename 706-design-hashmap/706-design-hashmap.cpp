class MyHashMap {
public:
    vector<pair<int, int>> res; 
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        bool exists = false; 
        int removed = -1;
        for(int i = 0; i < res.size(); i++) {
            if(res[i].first == key) {
                res[i].second = value; 
                exists = true; 
            }
            
            if(res[i].first == -1) removed = i;
        }
        if(!exists) {
            if(removed != -1) res[removed] = {key, value};
            else res.push_back({key, value});
        }
        return;
    }
    
    int get(int key) {
        for(auto& it : res) {
            if(it.first == key) return it.second;
        }
        
        return -1; 
    }
    
    void remove(int key) {
        for(auto& it : res) {
            if(it.first == key) {
                it.first = -1; 
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */