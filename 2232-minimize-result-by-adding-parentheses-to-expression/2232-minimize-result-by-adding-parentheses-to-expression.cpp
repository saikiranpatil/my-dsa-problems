class Solution {
public:
    int sti(string num){
        if(num.size() == 0) return 1;
        return stoi(num);
    }
    
    string minimizeResult(string exp) {
        int n = exp.size(), plus_idx = exp.find('+'), mn = INT_MAX, prod;
        string ans, curr, lf, ls, rf, rs;
        
        for(int i=0;i<plus_idx;i++){
            for(int j=plus_idx+1;j<n;j++){
                lf=exp.substr(0,i);
                ls=exp.substr(i, plus_idx-i);
                rf=exp.substr(plus_idx+1,j-plus_idx);
                rs=exp.substr(j+1, n-j-1);
                
                prod = sti(lf) * (sti(ls) + sti(rf)) * sti(rs);
                
                if(prod<mn){
                    mn=prod;
                    curr = exp; 
                    curr.insert(i,"(");
                    curr.insert(j+2,")");
                    ans=curr;
                }
            }
        }
        
        return ans;
    }
};

// cout<<exp.substr(0,i)<<" "<<exp.substr(i, plus_idx-i)<<" ";
// cout<<exp.substr(plus_idx+1,j-plus_idx)<<" "<<exp.substr(j+1, n-j-1)<<" ";
// cout<<curr<<endl;