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
    long long total =0, ans=0, sum;
    int maxProduct(TreeNode* root) {
        total = helper(root);
        helper(root);
        return ans % (int)(1e9 + 7);
    }
    
    int helper(TreeNode* root){
        if(!root) return 0;
        sum = root->val + helper(root->left) + helper(root->right);
        ans = max(ans, sum * (total - sum));
        return sum;
    }
};