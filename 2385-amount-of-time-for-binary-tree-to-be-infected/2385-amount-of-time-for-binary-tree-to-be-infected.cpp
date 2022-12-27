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
    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;
        
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root]=NULL;
        
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node;
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                TreeNode* curr=q.front();
                
                if(curr->val==start) node=curr;
                
                if(curr->left){
                    parent[curr->left]=curr;
                    q.push(curr->left);
                }
                if(curr->right){
                    parent[curr->right]=curr;
                    q.push(curr->right);
                }
                q.pop();
            }
        }
        
        return helper(root,parent,node);
    }
    
    int helper(TreeNode* root,unordered_map<TreeNode*, TreeNode*> parent, TreeNode* node){
        int ans=-1;
        
        queue<TreeNode*> q;
        q.push(node);
        node->val=-1;
        
        while(!q.empty()){
            int sz=q.size();
            ans++;
            while(sz--){
                TreeNode* curr=q.front();

                if(curr->left && curr->left->val != -1){
                    curr->left->val = -1;
                    q.push(curr->left);
                }

                if(curr->right && curr->right->val != -1){
                    curr->right->val = -1;
                    q.push(curr->right);
                }

                if(parent[curr] && parent[curr]->val != -1){
                    parent[curr]->val = -1;
                    q.push(parent[curr]);
                }
                
                q.pop();
            }
        }
        
        return ans;
    }
};