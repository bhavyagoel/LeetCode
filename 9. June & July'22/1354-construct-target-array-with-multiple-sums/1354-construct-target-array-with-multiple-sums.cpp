class Solution {
public:
    bool isPossible(vector<int>& t) {
        if(t.size()==1) return t[0]==1;
        priority_queue<int> pq; 
        long long int sum = 0; 
        for(int i = 0; i < t.size(); i++) {
            pq.push(t[i]);
            sum += t[i]; 
        }
        
        while(pq.top()!=1) {
            int num = pq.top(); 
            pq.pop(); 
            
            long long int rem = sum - num; 
            if(num <= rem) return false; 
            long long int tmp = num - ((num-1)/rem)*rem; 
            // int tmp = num-rem;
            // if (!((num-1)%rem)) tmp = 1;
            pq.push(tmp);
            sum = tmp+rem;
        }
        
        return true;
    }
};