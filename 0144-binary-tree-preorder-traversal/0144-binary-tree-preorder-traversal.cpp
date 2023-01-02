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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        
        stack<TreeNode*> stk;
        stk.push(root);
        
        while(!stk.empty()){
            int n=stk.size();
            while(n--){
                TreeNode* curr=stk.top();                
                ans.push_back(curr->val);
                stk.pop();
                if(curr->right!=NULL) stk.push(curr->right);
                if(curr->left!=NULL) stk.push(curr->left);
            }
        }
        
        return ans;
    }
};