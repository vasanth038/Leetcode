class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        priority_queue<int,vector<int> , greater<int>>pq;
        priority_queue<int,vector<int>>max_heap;
        for(int num : nums){
            pq.push(num);
            max_heap.push(num);
            if(pq.size() > 3) pq.pop();
            if(max_heap.size() > 2) max_heap.pop();
        }

        int p = 1;
        int n = 1;
         n =  1 ;
          while(!max_heap.empty()) {
             n*=max_heap.top();
             max_heap.pop();
          } 

        while(!pq.empty()){
             p*=pq.top();
             if(pq.size() == 1) n*=pq.top();
             pq.pop();
             
        }
        return max(p,n);
    }
};