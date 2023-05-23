class Bitset {
public:
    vector<bool> bits;
    int bit_count;
    bool isFlipped=false;
    
    Bitset(int size) {
        bits.resize(size, 0);
        bit_count=0;
    }
    
    void fix(int idx) {
        if((bits[idx] + isFlipped)%2==0){
            bit_count++;
            bits[idx]=!bits[idx];
        }
    }
    
    void unfix(int idx) {
        if((bits[idx] + isFlipped)%2!=0){
            bit_count--;
            bits[idx]=!bits[idx];
        }
    }
    
    void flip() {
        bit_count = bits.size()  - bit_count;
        isFlipped =! isFlipped;
    }
    
    bool all() {
        return bit_count==bits.size();
    }
    
    bool one() {
        return bit_count>=1;
    }
    
    int count() {
        return bit_count;
    }
    
    string toString() {
        string ans="";
        
        for(auto bit: bits) ans.push_back((bit + isFlipped) % 2 ? '1' : '0');
        
        return ans;
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