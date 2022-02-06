class MinStack {
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int val) {
        stack_.push(val); 
        if(stack_.top() <= min_stack.top()){
            min_stack.push(val);
        }
    }
    
    void pop() {
        if(stack_.top() == min_stack.top()){
            min_stack.pop();
        }
        stack_.pop();
    }
    
    int top() {
        return stack_.top(); 
    }
    
    int getMin() {
        return min_stack.top(); 
    }
    
private:
    stack<int> stack_;
    stack<int> min_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */