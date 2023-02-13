/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* ans=root;
        if(root==NULL) return ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int sz=q.size();
            vector<int> tmp;
            Node* prev = NULL;
            
            while(sz--){
                Node* p=q.front();
                q.pop();
                
                if(prev) prev->next = p;
                prev = p;
                
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
        }
        
        return ans;
    }
};