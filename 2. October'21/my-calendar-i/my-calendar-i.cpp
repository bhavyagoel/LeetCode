class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(int i = 0 ; i < cal.size(); i++){
            if((start >= cal[i].first && start < cal[i].second) or 
                (end > cal[i].first && end <= cal[i].second) or 
              (start <= cal[i].first && end >= cal[i].second)){
                return false;
            }
        }    
        cal.push_back(make_pair(start, end)); 
        return true;
    }
    
private:
    vector<pair<int, int>> cal;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */