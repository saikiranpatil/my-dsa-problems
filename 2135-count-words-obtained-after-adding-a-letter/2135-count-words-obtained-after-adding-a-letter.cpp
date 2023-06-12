class Solution {
public:
    int bitConverter(string& str){
        int ans = 0;
        
        for(auto c: str){
            ans += pow(2, c - 'a');
        }
        
        return ans;
    }
    
    bool isValidWord(string word, unordered_set<int>& nums){
        int target = bitConverter(word);
        
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