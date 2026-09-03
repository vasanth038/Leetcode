class Solution {
    private:
     static bool comp(const vector<int>&a,const vector<int>&b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
      }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);

        int cnt = 1;
        int end = intervals[0][1];
        int n = intervals.size();
        for(int i = 1;i<n;i++){
            if(end < intervals[i][1]){
              cnt++;
              end =intervals[i][1];
            }
        }

        return cnt;
    }
};