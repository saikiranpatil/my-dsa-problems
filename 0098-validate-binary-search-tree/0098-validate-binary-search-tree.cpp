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
    bool isValidBST(TreeNode* root, int* low=NULL, int* high=NULL) {
        if(!root) return true;
        if((low && root->val<=*low) || (high && root->val>=*high)) return false;
        if(root->left && root->left->val >= root->val) return false;
        if(root->right && root->right->val <= root->val) return false;
        return isValidBST(root->left, low, &(root->val)) && isValidBST(root->right, &(root->val), high);
    }
};