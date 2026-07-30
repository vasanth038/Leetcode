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
    void helper (TreeNode* node,vector<int>&a,vector<vector<int>>&ans){
        if(!node) return;
           a.push_back(node->val);
          if(node->left == NULL && node->right == NULL){
            ans.push_back(a);
          }

          if(node->left) helper(node->left,a,ans);
          if(node->right) helper(node->right,a,ans);
          a.pop_back();
        }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>>ans;
         vector<string>res;
         if(!root) return res;
         vector<int>a;
        helper(root,a,ans);
          for(int i = 0;i<ans.size();i++){
             string s ="";
             for(auto it : ans[i]){
                if(!s.empty()){
                    s+="->";
                }
                s+=to_string(it);
             }
             res.push_back(s);
          }
        return res;
    }
};