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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1;
        vector<int> leaf2;
        
        helper(root1,leaf1);
        helper(root2,leaf2);
        
        return leaf1 == leaf2;
    }
    
    void helper(TreeNode* root, vector<int>& nums){
        if(!root) return;
        if(root->left) helper(root->left,nums);
        if(root->right) helper(root->right,nums);
        if(!root->left && !root->right) nums.push_back(root->val);
    }
};