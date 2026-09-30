class Solution {
   
public:
    void sortColors(vector<int>& arr) {


        int n = arr.size();

        int cnt0 = 0 , cnt1 = 0, cnt2 = 0;

        for(auto i : arr){
             if(i == 0 ) cnt0++;
             else if(i == 1) cnt1++;
             else cnt2++;
        }

        for(int i = 0;i<n;i++){

            if(cnt0) {
                arr[i] = 0;
                cnt0--;
            }
            else if(cnt1){
                   arr[i] = 1;
                cnt1--;
            }
            else {
                  arr[i] = 2;
                cnt2--;
            }
             
        }

    
    }
};