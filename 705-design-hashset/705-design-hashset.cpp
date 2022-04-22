class MyHashSet {
public:
    list<int> arr[100];
    int hash = 100;
    MyHashSet() {
        
    }
    
    void add(int key) {
        int tmp = key % hash; 
        for(auto it : arr[tmp]) {
            if(it == key) return;
        }
        arr[tmp].push_back(key); 
        return;
    }
    
    void remove(int key) {
        int tmp = key % hash; 
        auto itr = arr[tmp].begin(); 
        
        while(itr != arr[tmp].end()) {
            if(*itr == key) {
                arr[tmp].erase(itr);
                return;
            }
            
            itr++;
        }
    }
    
    bool contains(int key) {
        int tmp = key % hash; 
        for(auto it : arr[tmp]) {
            if(it == key) return true;
        }
        return false; 
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */