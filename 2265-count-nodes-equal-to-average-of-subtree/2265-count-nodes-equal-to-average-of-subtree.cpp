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
    int count = 0;
    pair<int, int> helper(TreeNode* root){
        if(!root) return {0, 0};
        
        auto left = helper(root->left);
        auto right = helper(root->right);
        
        pair<int, int> ans = {left.first + right.first + root->val, left.second + right.second + 1};
        
        if(ans.first / ans.second == root->val) count++;
        
        return ans;
    }
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return count;
    }
};