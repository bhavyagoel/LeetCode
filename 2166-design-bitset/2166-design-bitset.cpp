class Bitset {
public:
    int flipped; 
    vector<int> bits; 
    int ones, zeros; 
    
    Bitset(int size) {
        bits.resize( size );
        fill(bits.begin(), bits.end(), 0);
        flipped = 0; 
        ones = 0; 
        zeros = size;
    }
    
    void fix(int idx) {
        if(!flipped) {
            if(!bits[idx]) {
                ones += 1; 
                zeros -= 1; 
            }
            bits[idx] = 1;
        }
        else {
            if(bits[idx]) {
                ones += 1; 
                zeros -= 1; 
            }
            bits[idx] = 0;
        }
    }
    
    void unfix(int idx) {
        if(!flipped) {
            if(bits[idx]) {
                ones -= 1; 
                zeros += 1;
            }
            bits[idx] = 0;
        }else{
            if(!bits[idx]) {
                ones -= 1; 
                zeros += 1;
            }
            bits[idx] = 1;
        }
    }
    
    void flip() {
        flipped = (flipped==0)?1:0;
        swap(ones, zeros); 
    }
    
    bool all() {
        return zeros>0?false:true; 
    }
    
    bool one() {
        return ones>0?true:false;
    }
    
    int count() {
        return ones; 
    }
    
    string toString() {
        string res = ""; 
        for(auto &it : bits) {
            if(flipped == 0) res += (it==0)?"0":"1";
            else res += (it==0)?"1":"0";
        }
        return res;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */