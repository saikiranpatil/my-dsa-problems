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
    int minDiffInBST(TreeNode* root) {
        vector<int> nums;
        queue<TreeNode*> q;
        q.push(root);
        int ans = INT_MAX;
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                TreeNode* curr = q.front();
                q.pop();
                
                nums.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<nums.size()-1;i++){
            ans = min(ans, nums[i+1] - nums[i]);
        }
        
        return ans;
    }
};