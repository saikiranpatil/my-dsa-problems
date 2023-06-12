class Solution {
public:
    int bitConverter(string& w){
        return accumulate(begin(w), end(w), 0, [](int mask, char ch){ return mask + (1 << (ch - 'a')); });  
    }
    
    bool isValidWord(string word, unordered_set<int>& nums){        
        int  target = bitConverter(word);
        
        for(int i=0;i<32;i++){
            if((target>>i) & 1){
                int curr = target - pow(2, i);
                
                if(nums.find(curr) != nums.end()){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> nums;
        int ans = 0;
        int curr;
        
        for(auto word: startWords){
            curr = bitConverter(word);
            nums.insert(curr);
        }
        
        for(auto word: targetWords){
            if(isValidWord(word, nums)){
                ans++;
            }
        }
        
        return ans;
    }
};