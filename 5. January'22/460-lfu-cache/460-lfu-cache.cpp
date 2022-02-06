class LFUCache {
private:
    struct node {
        int key, val, cnt; 
        node* next; 
        node* prev; 
        node(int _key, int _val) {
            key = _key; 
            val = _val; 
            cnt = 1;
        }
    };
    struct list {
        int size; 
        node* head; 
        node* tail; 
        
        list() {
            head = new node(-1, -1);
            tail = new node(-1, -1);
            head->next = tail; 
            tail->prev = head; 
            size = 0; 
        }
        
        void addFront(node* _node) {
            node* tmp = head->next; 
            _node->next = tmp; 
            _node->prev = head;
            
            head->next = _node; 
            tmp->prev = _node;
            size++;
        }
        
        void removeNode(node* _node) {
            node* prv = _node->prev; 
            node* nxt = _node->next;
            
            prv->next = nxt;
            nxt->prev = prv;
            size--;
        }
    };
    unordered_map<int, node*> keyNode; 
    unordered_map<int, list*> freqMap;
    int maxSizeCache; 
    int minFreq; 
    int currSize;
    
    void updateFreqMap(node* _node) {
        keyNode.erase(_node->key);
        freqMap[_node->cnt]->removeNode(_node);
        if(_node->cnt == minFreq and freqMap[_node->cnt]->size==0) {
            minFreq++;
        }
        list* tmp = new list(); 
        if (freqMap.find(_node->cnt+1) != freqMap.end()) {
            tmp = freqMap[_node->cnt + 1];
        }
        _node->cnt += 1;
        tmp->addFront(_node);
        freqMap[_node->cnt] = tmp;
        keyNode[_node->key] = _node;
        return;
    }
public:
    LFUCache(int capacity) {
        maxSizeCache = capacity; 
        minFreq = 0; 
        currSize = 0; 
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()) {
            node* _node = keyNode[key];
            int val = _node->val;
            updateFreqMap(_node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSizeCache==0) {
            return;
        }
        if (keyNode.find(key) != keyNode.end()) {
            node* _node = keyNode[key];
            _node->val = value; 
            updateFreqMap(_node);
        }else {
            if(currSize == maxSizeCache) {
                list* _list = freqMap[minFreq];
                keyNode.erase(_list->tail->prev->key);
                freqMap[minFreq]->removeNode(_list->tail->prev);
                currSize--;
            }
            currSize++;
            minFreq = 1;
            list* listFreq = new list(); 
            if(freqMap.find(minFreq) != freqMap.end()) {
                listFreq = freqMap[minFreq];
            }
            node* _node = new node(key, value);
            listFreq->addFront(_node);
            keyNode[key] = _node;
            freqMap[minFreq] = listFreq;
        }
        return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */