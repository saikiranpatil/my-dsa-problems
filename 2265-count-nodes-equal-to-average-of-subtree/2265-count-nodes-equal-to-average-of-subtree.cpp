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
    pair<int,int> solve(TreeNode* root){
        if(root==NULL) return {0,0};
        auto left=solve(root->left);
        int l_sum=left.first;
        int l_cnt=left.second;
        auto right=solve(root->right);
        int r_sum=right.first;
        int r_cnt=right.second;
        int sum=root->val+l_sum+r_sum;
        int cnt=l_cnt+r_cnt+1;
        if(root->val==sum/cnt)ans++;
        return {sum,cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};