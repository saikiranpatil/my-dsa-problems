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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        vector<TreeNode*> nodes(999999, NULL);
        vector<bool> isChild(999999, false);
        
        for(auto desc: descriptions){
            if(nodes[desc[0]] == NULL){
                TreeNode* root = new TreeNode(desc[0]);
                nodes[desc[0]] = root;
            }
            
            if(nodes[desc[1]] == NULL){
                TreeNode* child = new TreeNode(desc[1]);
                nodes[desc[1]] = child;
            }
            
            isChild[desc[1]] = true;
            
            if(desc[2]) nodes[desc[0]]->left = nodes[desc[1]];
            else nodes[desc[0]]->right = nodes[desc[1]];
        }
        
        for(int i=1;i<=999999;i++){
            if(nodes[i] && !isChild[i]) return nodes[i];
        }
        
        return NULL;
    }
};