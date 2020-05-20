/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void inorderTraversal(TreeNode* root, vector<int>& sortedList, int& count, int& k){
        if(!root) return ;
        
        inorderTraversal(root->left, sortedList, count, k);
        if(count == k) return;
        sortedList.push_back(root->val);
        count++;
        inorderTraversal(root->right, sortedList, count, k);
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> sortedList;
        int count = 0;
        inorderTraversal(root, sortedList, count, k);
        return sortedList[k-1];
    }
};
