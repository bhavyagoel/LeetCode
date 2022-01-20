class LRUCache {
    
private:
    class node {
        public :
            int key;
            int val; 
            node* next; 
            node* prev; 
            node(int _key, int _val) {
                key = _key; 
                val = _val;
            }
    };
    
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    
    int cap; 
    unordered_map<int, node*> m;
    
public:
    LRUCache(int capacity) {
        cap = capacity; 
        head->next = tail; 
        tail->prev = head; 
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1; 
        
        node* tmp = m[key];
        
        int val = tmp->val;
        m.erase(key);
        
        node* ahead = tmp->next; 
        node* back = tmp->prev; 
        
        back->next = ahead; 
        ahead->prev = back;        
        
        put(key, val);
        return val;         
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()) {
            node* tmp = m[key];
            m.erase(key);
            
            node* ahead = tmp->next; 
            node* back = tmp->prev; 

            back->next = ahead; 
            ahead->prev = back;
        }
        
        if(m.size()==cap) {
            node* prv = tail->prev;
            node* back = prv->prev; 
            back->next = tail; 
            tail->prev = back;
            
            m.erase(prv->key);
            
            node* tmp = new node(key, value);
            node* nxt = head->next;
            head->next = tmp; 
            tmp->prev = head; 
            
            tmp->next = nxt; 
            nxt->prev = tmp;
            
            m[key] = tmp;
            return;
        }else {
            node* tmp = new node(key, value);
            node* nxt = head->next;
            head->next = tmp; 
            tmp->prev = head; 
            
            tmp->next = nxt; 
            nxt->prev = tmp;
            
            m[key] = tmp;
            return;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */