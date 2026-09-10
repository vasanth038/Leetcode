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

      pair<int,int> helper(TreeNode* node ,int &ans){
         
         if(!node) return {0,0};

             pair<int,int>left = helper(node->left , ans) ;
             pair<int,int>right = helper(node->right,ans) ;  
              
              int n = 1+left.second+right.second;  
             int sum = (node->val + left.first + right.first);
              int avg = round(sum/n);
              if(node->val == avg){
                 ans++;
              }
           
           return {sum , n};
          
      }

       
public:
    int averageOfSubtree(TreeNode* root) {

           int ans = 0;
        helper(root,ans);
         return ans;
    }
};