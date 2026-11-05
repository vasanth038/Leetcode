class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {

        sort(arr2.begin(), arr2.end());

        int count = 0;

        for (auto x : arr1) {

            auto it = upper_bound(arr2.begin(), arr2.end(), x + d);
            if ( it != arr2.begin() ){
                   it--;
               if(abs(x - *it) > d) count++;
            }
            else count++;
        }

        return count;
    }
};