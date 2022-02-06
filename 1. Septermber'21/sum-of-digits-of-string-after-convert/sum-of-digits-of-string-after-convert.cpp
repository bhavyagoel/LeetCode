class Solution {
public:
    int getLucky(string s, int k) {
        
        string sum = ""; 
        int sumN = 0;
        bool flag; 
        while(s != "") { 
            if(isalpha(s.back())) {
                sum += to_string((s.back() - 'a'  + 1 ));
                s.pop_back(); 
                flag = true;
            }
            else {
                sumN += (s.back() - '0' );
                s.pop_back(); 
                flag = false; 
            }
            
        }
        
        if(k == 0) {
            return sumN;
        }
        k--;
        if (flag) return getLucky(sum, k); 
        
        return getLucky(to_string(sumN), k);
    }
};