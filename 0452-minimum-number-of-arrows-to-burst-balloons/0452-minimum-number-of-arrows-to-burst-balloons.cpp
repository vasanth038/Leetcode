class Solution {
    private:
      static bool comp (const vector<int>&a ,const vector<int>&b ){
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
      }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(),points.end(),comp);

        int cnt = 1;
        int end = points[0][1];
         int n = points.size();
        for(int i = 1;i<n;i++){

            if(end < points[i][0]){
                cnt++;
                end = points[i][1];
            }

        }

        return cnt;

    }
};