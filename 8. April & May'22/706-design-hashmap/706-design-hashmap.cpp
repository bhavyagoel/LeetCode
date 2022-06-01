class MyHashMap {
public:
    list<pair<int, int>> arr[100];
    int hash = 100;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        int tmp = key % hash; 
        for(auto &it : arr[tmp]) {
            if(it.first == key) {
                it.second = value;
                return;
            }
        }
        arr[tmp].push_back({key, value}); 
        return;
    }
    
    int get(int key) {
        int tmp = key % hash; 
        for(auto it : arr[tmp]) {
            if(it.first == key) return it.second;
        }
        
        return -1; 
    }
    
    void remove(int key) {
        
        int tmp = key % hash; 
        auto itr = arr[tmp].begin(); 
        
        while(itr != arr[tmp].end()) {
            if(itr->first == key) {
                arr[tmp].erase(itr);
                return;
            }
            
            itr++;
        }
        return;        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */