class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {

           vector<int>freq(10,0);

         for(auto i : digits) freq[i]++;
           
           vector<int>ans;
         for(int i = 100;i<1000;i+=2){

              int d1 = i%10;
              int d2 = (i/10)%10;
              int d3 = (i/100)%10;
           
            vector<int>need(10,0);
            need[d1]++;
            need[d2]++;
            need[d3]++;

            if(freq[d1] >= need[d1] && freq[d2] >= need[d2] &&  freq[d3] >= need[d3]){
                ans.push_back(i);
            }
                     
         }

         return ans;
         
    }
};