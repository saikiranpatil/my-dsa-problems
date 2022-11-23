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
    bool isSymmetric(TreeNode* root) {
        if(!root || (!root->left && !root->right)) return true;
        if((!root->left && root->right) || (root->left && !root->right)) return false;
        return helper(root->left,root->right);
    }

    bool helper(TreeNode* leftTree, TreeNode* rightTree) {
        if(!leftTree && !rightTree) return true;
        if((!leftTree && rightTree) || (leftTree && !rightTree)) return false;
        if(leftTree->val!=rightTree->val) return false;
        return(helper(leftTree->left,rightTree->right) && helper(leftTree->right, rightTree->left));
    }
};