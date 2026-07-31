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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       map<int,map<int,multiset<int>>>mpp;
       if(!root) return{{}};
       queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            int k =q.size();
            while(k--){
                auto it = q.front();
                auto node = it.first;
                int col = it.second.second;
                int row = it.second.first;
                q.pop();
                mpp[col][row].insert(node->val);
                if(node->left) q.push({node->left,{row+1,col-1}});
                if(node->right) q.push({node->right,{row+1,col+1}}); 
            } 
        }
        vector<vector<int>>ans;
        for(auto &col : mpp){
             vector<int>a;
             for(auto &rows : col.second ){
                 a.insert(a.end(),rows.second.begin(),rows.second.end());
             }
           ans.push_back(a);

        }
        return ans;
        
    }
};