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
    vector<vector<int>> ans;
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> tmp;
        helper(root, targetSum, tmp);
        return ans;
    }
    
    void helper(TreeNode* root, int sum, vector<int> tmp){
        if(!root) return;
        
        tmp.push_back(root->val);
        sum -= root->val;
        
        if(!root->left && !root->right && !sum) ans.push_back(tmp);
        if(root->left) helper(root->left, sum, tmp);
        if(root->right) helper(root->right, sum, tmp);
    }
};