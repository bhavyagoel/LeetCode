class Solution {
public:
    int largestInteger(int num) {
        vector<int> odd; 
        vector<int> even; 
        
        int cpy = num; 
        while(cpy){
            int tmp = cpy%10; 
            cpy /= 10; 
            if(tmp%2) odd.push_back(tmp);
            else even.push_back(tmp); 
        }
        
        sort(odd.begin(), odd.end()); 
        sort(even.begin(), even.end()); 
        
        int i = 0, j = 0; 
        long long int mult = 1;
        int res = 0; 
        while(num){
            int tmp = num%10; 
            num /= 10; 
            if(tmp%2) res += mult*odd[i++];
            else res += mult*even[j++];
            
            mult *= 10;
        }
        
        return res; 
    }
};