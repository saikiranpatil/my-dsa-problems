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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string tmp="";
        helper(root, ans, tmp);
        return ans;
    }
    
    void helper(TreeNode* root, vector<string>& ans, string tmp){
        if(!root->left && !root->right){
            tmp+=to_string(root->val);
            ans.push_back(tmp);
            return;
        }
        
        if(root->left) helper(root->left,ans,tmp+to_string(root->val)+"->");
        if(root->right) helper(root->right,ans,tmp+to_string(root->val)+"->");
    }
};