class CustomStack {
public:
    CustomStack(int maxSize) {
        this->n = maxSize;
        stk.resize(n);
    }
    
    void push(int x) {
        if (top==n-1) return; 
        stk[++top] = x; 
        return;
    }
    
    int pop() {
        if(top<0) return -1;
        return stk[top--];
    }
    
    void increment(int k, int val) {
        
        k = k>top?top+1:k;
        for(int i = 0 ; i < k; i++) {
            stk[i] += val;
        }
        return;
    }
private:
    int n; 
    vector<int> stk;
    int top = -1; 
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */