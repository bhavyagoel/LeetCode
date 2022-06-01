/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> res; 
    int pos = 0; 
    
    stack<NestedInteger> temp; 
    void helper(vector<NestedInteger> &nestedList) {
        int n = nestedList.size(); 
        
        for(int i = 0; i < n; i++) {
            temp.push(nestedList[i]); 
            
            while(!temp.empty()){
                int k = temp.size(); 
                while(k--){
                    NestedInteger top = temp.top();
                    temp.pop(); 
                    
                    if(top.isInteger()) res.push_back(top.getInteger());
                    else {
                        helper(top.getList());
                    }
                }
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        helper(nestedList); 
    }
    
    int next() {
        return res[pos++]; 
    }
    
    bool hasNext() {
        return pos!=res.size(); 
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */