class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       
    priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>> >pq;
       for(int i = 0;i<arr.size();i++){
        pq.push({arr[i] , i});
       }

       int  k = 1;
       vector<int>ans(arr.size());
       while(!pq.empty()){

        auto it = pq.top();
        pq.pop();
        int ind = it.second;
        ans[ind] = k;
        if(!pq.empty() && pq.top().first != it.first) k++;
       }
       return ans;
    }
};