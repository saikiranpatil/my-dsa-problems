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
    int getMinimumDifference(TreeNode* root) {
        return helper(root, 10000001, 10000001, -10000001);
    }
    
    int helper(TreeNode* root, int ans, int mx, int mn){
        if(!root) return ans;
        
        ans = min(ans, min(mx - root->val, root->val - mn));
        ans = min(ans, min(helper(root->left, ans, root->val, mn), helper(root->right, ans, mx, root->val)));
        
        return ans;
    }
};