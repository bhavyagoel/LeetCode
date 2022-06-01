class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()) {
            q2.push(q1.front()); 
            q1.pop();
        }
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return;
    }
    
    int pop() {
        int temp = q1.front(); 
        q1.pop();
        return temp;
    }
    
    int top() {
        return q1.front(); 
    }
    
    bool empty() {
        return q1.empty();
    }
private:
    queue<int> q1;
    queue<int> q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */