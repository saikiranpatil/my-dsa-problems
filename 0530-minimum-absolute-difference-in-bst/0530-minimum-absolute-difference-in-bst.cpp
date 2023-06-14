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
    vector<int> nums;
    int ans = INT_MAX;
    void helper(TreeNode* root){
        if(!root) return;
        
        helper(root->left);
        nums.push_back(root->val);
        helper(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        helper(root);
        
        for(int i=0;i<nums.size()-1;i++){
            ans = min(ans, nums[i+1] - nums[i]);
        }
        
        return ans;
    }
};