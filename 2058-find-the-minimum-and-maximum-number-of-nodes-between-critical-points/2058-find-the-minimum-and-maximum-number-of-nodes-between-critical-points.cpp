/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    private:
    void  helper(ListNode* node ,int n , int  p , int first ,int last ,vector<int>&ans){
        if(!node){
            return;
        } 
        
        if(node->next && p != -1 ){
           if( (node->val > p && node->next->val < node->val ) || (node->val < p && node->val < node->next->val ) ) {
           if(last != -1 ) {
                  ans[0] = min(ans[0] , n-last);
           }
           if(first != -1) {
            ans[1] = max(ans[0],n-first);
           }
             last = n;
             if(first == -1) first = n;
           }
           
        }

        p = node->val;

        helper(node->next,n+1,p,first,last,ans);
     }
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
             vector<int> ans(2);
             ans[0] = 1e9;
             ans[1] = -1;
           helper(head, 1 , -1,-1,-1 , ans) ;

           if(ans[0] == 1e9) return {-1,-1};

           return ans;
    }
};