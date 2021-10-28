class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        res.push_back(homepage); 
        curr = 0; 
    }
    
    void visit(string url) {
        if(curr== res.size()-1){
            res.push_back(url); 
            curr+=1; 
        } else {
            int i = res.size()-1; 
            while(i>curr){
                res.pop_back(); 
                i--; 
            }
            res.push_back(url);
            curr = res.size()-1;
        }        
    }
    
    string back(int steps) {
        
        steps = steps>curr?curr:steps;
        while(steps){
            curr--;
            steps--; 
        }
        return res[curr];
    }
    
    string forward(int steps) {
        steps = steps>=(res.size()-curr)?(res.size()-1-curr):steps;
        while(steps){
            curr++;
            steps--; 
        }
        return res[curr];
    }
    
private:
    vector<string> res;
    int curr; 
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */