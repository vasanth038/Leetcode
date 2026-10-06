class Solution {

public:
    int findRow(vector<vector<int>>& mat, int col) {
        int maxi = 0;
        int row = -1;

        for (int i = 0; i < mat.size(); i++) {

            if (maxi < mat[i][col]) {
                maxi = mat[i][col];
                row = i;
            }
        }

        return row;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();
        int l = 0;
        int r = m - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int row = findRow(mat, mid);
            int left = mid == 0 ? -1 : mat[row][mid - 1];
            int right = mid == m - 1 ? -1 : mat[row][mid + 1];
             int val = mat[row][mid];
            if(left < val && val > right) return {row,mid};
            
            if(left > right) r = mid-1;
            else l = mid+1;
        }

        return {-1, -1};
    }
};