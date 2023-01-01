class SGTree{
    vector<int> seg; 
public:    
    SGTree(int n){
        seg = vector<int>(4*n+1); 
    }
    
    void build(int idx, int low, int high, vector<int>& arr) {
        if(low == high) {
            seg[idx] = arr[low];
            return;
        }
        
        int mid = low + (high - low) / 2; 
        build(2*idx+1, low, mid, arr);
        build(2*idx+2, mid+1, high, arr);
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
        return;
    }
    
    int query(int idx, int low, int high, int l, int r) {        
        // no overlap
        if(r < low or high < l) return 0;
        
        // complete overlap
        if(low >= l and high <= r) return seg[idx];
        
        int mid = low + (high - low)/2;
        int left = query(2*idx+1, low, mid, l, r);
        int right = query(2*idx+2, mid+1, high, l, r);
        return left+right;
    }
    
    void update(int idx, int low, int high, int i, int val){
        if(low == high) {
            seg[idx] = val;
            return;
        }
        
        int mid = low + (high - low)/2; 
        if(i <= mid) update(2*idx+1, low, mid, i, val);
        else update(2*idx+2, mid+1, high, i, val);
        
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
        return;
    }
};

class NumArray{
    int n = 0;
    SGTree s;
public:
    NumArray(vector<int>& nums) : s(nums.size()){
        n = nums.size(); 
        s.build(0, 0, n-1, nums);
    }
    
    void update(int index, int val) {
        s.update(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        
        return s.query(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */