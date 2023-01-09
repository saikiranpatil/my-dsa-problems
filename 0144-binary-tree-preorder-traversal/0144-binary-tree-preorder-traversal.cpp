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
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        while (curr != NULL || !stk.empty()) {
            while (curr != NULL) {
                stk.push(curr);
                ans.push_back(curr->val);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            curr = curr->right;
        }
        return ans;
    }
};