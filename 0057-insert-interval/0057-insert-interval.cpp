class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int n = intervals.size();
         int start = newInterval[0];
         int end = newInterval[1];
       vector<vector<int>>ans;
         int i = 0;
         while(i < n &&  intervals[i][1] < start){
             ans.push_back({intervals[i][0],intervals[i][1]});
             i++;
         }

         while(i < n && intervals[i][0] <= end ){
             
             start = min(intervals[i][0] , start);
             end = max(intervals[i][1] , end);
             i++;
         }
          ans.push_back({start,end});

      while(i < n){
          ans.push_back({intervals[i][0],intervals[i][1]});
             i++;
      }
     
      return ans;
    }
};