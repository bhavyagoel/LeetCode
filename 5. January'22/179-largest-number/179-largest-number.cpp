class Solution {
private:
    static bool checkSmaller(string& a, string& b, int i, int j){
        int m = a.length(); 
        int n = b.length(); 
        
        while(i<m and j<n) {
            if(a[i]==b[j]) {
                i++;
                j++;
            }
            else if(a[i]>b[j]) return true;
            else return false; 
        }
        
        if (i>=m && j>=n) return true;
        else if(i>=m) return checkSmaller(a, b, 0, j);
        else if(j>=n) return checkSmaller(a, b, i, 0);
        else return true;
    }
    
    static bool comparator(string& a, string& b){
        return checkSmaller(a, b, 0, 0);
    }
    
    /**
    static bool cmp(string& x , string& y){
        string xy = x.append(y);
        string yx = y.append(x);
        return xy>=yx;
    }
    **/
public:
    string largestNumber(vector<int>& nums) {
        vector<string> temp; 
        for(auto it : nums) {
            temp.push_back(to_string(it));
        }
        
        
        // We checked for all zeros at start because the inbuilt sort function crashes in cases of all zeros in the array
        // [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
        // https://stackoverflow.com/questions/28060435/garbage-value-added-to-vector-following-a-sort-operation
        
        int i = 0; 
        while(i<temp.size() and temp[i]=="0") i++;
        if(i==temp.size()) return "0";
        
        sort(temp.begin(), temp.end(), comparator); 
        string res = ""; 
        for(auto it : temp) {
            res += it;
        }
        
        return res; 
    }
};