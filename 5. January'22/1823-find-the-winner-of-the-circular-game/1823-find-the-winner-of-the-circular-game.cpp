class Solution {
private:
    void CircularList(list<int>:: iterator& it, list<int> &l, int k) {
        if (l.size() == 1) return;
        
        int temp = k;
        while(--temp) {
            // cout<<"TEMP "<<temp<<" "<<*it<<endl;
            ++it; 
            if (it == l.end()) { 
                it = l.begin();
            }
           
        }
        auto prev = it++;
        if (it == l.end()) { 
            it = l.begin();
        }
        l.erase(prev);
        return CircularList(it, l, k);
    }
    
    
public:
    int findTheWinner(int n, int k) {
        list<int> l; 
        for(int i = 1; i <= n; i++){
            l.push_back(i); 
        }
        list<int> :: iterator it = l.begin(); 
        CircularList(it, l, k);
        return l.front();
    }
};