/*

customers per row
wealth is the sum of elements in rows
[[1,2,3], 6
 [3,2,1]] 6

max wealth value returned

[[1,5],  6
 [7,3],  10
 [3,5]]  8
 
 return 10

[[2,8,7], 17
 [7,1,3], 11
 [1,9,5]] 15
return 17

sum each row, keeping track of the maximum sum
O(m*n)

*/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        // initializing these values ahead of time saves loop calls
        int m_len = accounts.size();
        int n_len = accounts[0].size();
        
        // track maximum sum, don't need to initialize to negative INF
        // due to accounts cannot be negative
        int max_sum = 0;
        // for loop of customers(m)
        for (int m = 0; m < m_len; m++) {
          // customer's sum initialized
          int max_c = 0;
          // for loop of banks(n), can assume 0 index due to at least 1 customer
          for (int n = 0; n < n_len; n++) {  
            // sum all banks for c_sum 
            max_c += accounts[m][n];
          }
          // update max sum with current max and customers sum
            max_sum = std::max(max_c,max_sum);
        }
       return max_sum;
    }
};