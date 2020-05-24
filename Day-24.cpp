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
    
    TreeNode* makeTree(vector<int>& preorder, int start, int end){
        
        if(start > end) return NULL;
        TreeNode* root = new TreeNode(preorder[start]);
        if(start == end) return root;
        
        int right_start;
        for(int i = start + 1; i <= end; i++){
            if(preorder[start] < preorder[i]){
                right_start = i;
                break;
            }
        }
        
        root->left = makeTree(preorder, start+1, right_start-1);
        root->right = makeTree(preorder, right_start, end);
        
        return root;
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        return makeTree(preorder, 0, n-1);
    }
};
