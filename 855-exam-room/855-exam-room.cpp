class ExamRoom {
public:
    ExamRoom(int n) {
        this->n = n;
    }
    
    int seat() {
        if(seats.size()==0) {
            seats.push_back(0); 
            // showlist(seats);
            return 0; 
        }
        
        int d = max(seats.front(), n-1-seats.back());
        auto curr = seats.begin(); 
        auto nxt = seats.begin(); 
        advance(nxt, 1);
        
        while(nxt!=seats.end()) {
            d = max(d, (*nxt-*curr)/2);
            ++curr;
            ++nxt;
        }
        if(seats.front()==d) {
            seats.insert(seats.begin(), 0);
            // showlist(seats);
            return 0;
        }
        
        curr = seats.begin(); 
        nxt = seats.begin(); 
        advance(nxt, 1);
        
        while(nxt!=seats.end()) {
            int diff = (*nxt-*curr)/2;
            int ins = (*nxt+*curr)/2;
            if(diff == d) {
                
                seats.insert(nxt, ins);
                return ins; 
            }
            ++curr;
            ++nxt;
        }
        seats.push_back(n-1);
        // showlist(seats);
        return n-1;
        
    }
    
    void leave(int p) {
        seats.remove(p);
        // showlist(seats);
        return;
    }
    
private:
    list<int> seats;
    int n;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */