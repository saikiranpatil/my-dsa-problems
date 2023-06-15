class ATM {
public:
    vector<long long> bank;
    int notes[5]={20, 50, 100, 200, 500};
    ATM() {
        bank.resize(5,0);
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0;i<5;i++){
            bank[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ans(5, 0);
        for(int i=4;i>=0;i--){
            ans[i]=amount/notes[i];
            if(ans[i] > bank[i]){
                ans[i] = bank[i];
            }
            amount -= ans[i]*notes[i];
        }
        
        if(amount != 0){
            return {-1};
        }
        
        for(int i=0;i<5;i++){
            bank[i] -= ans[i];
        }
        
        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */