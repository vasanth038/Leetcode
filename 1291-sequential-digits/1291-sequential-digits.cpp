class Solution {
    vector<int>seq;
    private:
     void helper(vector<int>&seq , int cur){
       if(cur > 1000000000) return;
         
         seq.push_back(cur);
         int last = cur%10;
         if(last < 9 ){
             int next = (cur*10)+(last+1);
             helper(seq , next) ;
         }
        

     }

public:
      Solution (){
        for(int i = 1;i<9;i++){
            helper(seq , i );
        }
        sort(seq.begin(),seq.end()) ;
      }
    vector<int> sequentialDigits(int low, int high) {
         
         vector<int>ans ;
          for(int it : seq){
            if(it <= high && it >= low ) ans.push_back(it) ;
            if(it > high) break;
          }
          return ans ;
        

    }
};