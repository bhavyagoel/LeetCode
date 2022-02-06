class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        /**
        while(!s1.empty()) {
            int tmp = s1.top();
            s2.push(tmp); 
            s1.pop(); 
        }
        s1.push(x); 
        while(!s2.empty()) {
            int tmp = s2.top(); 
            s1.push(tmp);
            s2.pop();
        }
        **/
        input.push(x); 
        return;
    }
    
    int pop() {
        if (!output.empty()) {
            int tmp = output.top(); 
            output.pop();
            return tmp; 
        }
        while(!input.empty()) {
            int tmp = input.top(); 
            output.push(tmp); 
            input.pop(); 
        }
        
        int tmp = output.top(); 
        output.pop(); 
        return tmp;
    }
    
    int peek() {
        if (!output.empty()) {
            int tmp = output.top(); 
            return tmp; 
        }
        while(!input.empty()) {
            int tmp = input.top(); 
            output.push(tmp); 
            input.pop(); 
        }
        
        int tmp = output.top(); 
        return tmp;
    }
    
    bool empty() {
        return output.empty() and input.empty();
    }
    
private:
    stack<int> input; 
    stack<int> output;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */