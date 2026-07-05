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
         map<int,int>mpp;
         queue<TreeNode*>st;
         st.push(root);
         int level = 0;
         while(!st.empty()){
            
          int size = st.size();
        while(size--){
            TreeNode* node = st.front();
            st.pop();
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
            
            mpp[level] = node->val;
        }
            level++;
         }
         vector<int>ans;
         for(auto it :mpp){
          ans.push_back(it.second);
         }
         return ans;
    }
};