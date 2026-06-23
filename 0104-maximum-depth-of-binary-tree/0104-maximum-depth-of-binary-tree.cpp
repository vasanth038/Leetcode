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
    private:
     int helper(TreeNode* node){
        if(node == nullptr) return 0;
        return 1 + max(helper(node->left) , helper(node->right) ) ;
     }
public: 
    int maxDepth(TreeNode* root) {
         return helper(root) ;
    }
};