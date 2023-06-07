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
        unordered_map<int, TreeNode*> nodes;
        unordered_map<int, bool> isChild;
        
        for(auto desc: descriptions){
            if(nodes.find(desc[0]) == nodes.end()){
                TreeNode* root = new TreeNode(desc[0]);
                nodes[desc[0]] = root;
            }
            
            if(nodes.find(desc[1]) == nodes.end()){
                TreeNode* child = new TreeNode(desc[1]);
                nodes[desc[1]] = child;
            }
            
            isChild[desc[1]] = true;
            
            if(desc[2]) nodes[desc[0]]->left = nodes[desc[1]];
            else nodes[desc[0]]->right = nodes[desc[1]];
        }
        
        for(auto node: nodes){
            if(!isChild[node.first]) return node.second;
        }
        
        return NULL;
    }
};