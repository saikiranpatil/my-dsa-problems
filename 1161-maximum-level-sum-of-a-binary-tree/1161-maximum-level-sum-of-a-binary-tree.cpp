/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        int ans = -1;
        int lvl=0;
        int curr;
        int mx=INT_MIN;
        
        while(!q.empty()){
            int sz = q.size();
            curr = 0;
            lvl++;
            
            while(sz--){
                TreeNode* front = q.front();
                q.pop();
                
                curr += front->val;
                
                if(front->left){
                    q.push(front->left);
                }
                
                if(front->right){
                    q.push(front->right);
                }
            }
            
            if(curr > mx){
                mx = curr;
                ans = lvl;
            }
        }
        
        return ans;
    }
};