/*

[1,2,3,1,1,3]
 i     j
 i       j
       i j
     i     j


[1,1,1,1]
 i j
 i   j
 i     j
   i j
   i   j
     i j

[1,2,3]
 i     j
   i   j
     
[1,2,3,1,1,3]
 i     j
 i       j
     i     j
       i j
         
      
     
    
contraints
- not guaranteed to have a pair, edge case
- no algo or space restrictions

pcode
- return 0 if length of nums < 2
- establish good_pair counter
- 
- loop through nums i from 0 to less than length - 1
- sub loop through nums j from i+1 to less than length
- increment a good_pairs counter each time nums[i] == nums[j]
- 
- return good_pairs counter

*/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
      int nums_size = nums.size();
      int good_pairs = 0;
        
      if (nums_size < 2) return 0;
        
      for (int i=0; i<nums_size-1; i++)
          for (int j=i+1; j<nums_size; j++)
              if (nums[i] == nums[j]) {
                  good_pairs++;
                  //cout << i << " " << j << endl;
              } else if (i == 2) {
                  //cout << i << " " << j << endl;                  
              }
        
      return good_pairs;
    }
};