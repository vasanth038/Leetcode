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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
        ans.push_back(root->val);
         queue<TreeNode*>st;
         st.push(root);
         
         while(!st.empty()){
            bool flag = false;
          int size = st.size();
        while(size--){
            TreeNode* node = st.front();
            st.pop();
            
            if(node->right && !flag) {
                ans.push_back(node->right->val);
                flag = true;
            }
           if(node->left && !flag) {
                ans.push_back(node->left->val);
                       flag = true;
            }
            if(node->right ) {
              st.push(node->right);
            }
            if(node->left) st.push(node->left);
        
        }

         }
      
      
         return ans;
    }
};