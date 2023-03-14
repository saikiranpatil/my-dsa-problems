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
    int ans=0;
    
    int sumNumbers(TreeNode* root) {
        helper(root, root->val);
        return ans;
    }
    
    void helper(TreeNode* root, int val){
        if(root->left==NULL && root->right==NULL){
            ans+=val;
            return;
        }
        
        if(root->left) helper(root->left, 10 * val + root->left->val);
        if(root->right) helper(root->right, 10 * val +  root->right->val);
        
        return;
    }
};