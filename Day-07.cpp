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
    
    void traverseTree(TreeNode* root, unordered_map<int, pair<int, int>>& m, int h){
        if(!root) return ;
        
        
        if(root->left != NULL)
            m[root->left->val] = make_pair(root->val, 1+h);
        if(root->right != NULL)
            m[root->right->val] = make_pair(root->val, 1+h);
            
        traverseTree(root->left, m, h+1);
        traverseTree(root->right, m, h+1);
        
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int, pair<int, int>> m;
        
        traverseTree(root, m, 0);
        
        if(m[x].first != m[y].first  && m[x].second == m[y].second) return true;
        
        return false;
    }
};
