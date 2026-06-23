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
     int helper(TreeNode* node , int &dai ){
        if(node == nullptr) return 0;
         int left = helper(node->left,dai) ;
         int right = helper(node->right , dai);
           dai = max(dai , left+right) ;
           return 1+max(left,right) ;
     }
public:
    int diameterOfBinaryTree(TreeNode* root) {
         int dai = 0;
          helper(root, dai) ;
         return dai;
    }
};