/*
Constraints
- O(n) runtime
- O(1) space

Diagram

[1,2,3,4]
 1 3 6 10

[1,3,6,10]

 0 1 2 3 4 
[1,1,1,1,1]
[1,2,1,1,1]
[1,2,3,4,5]
           i


pCode
- loop through each entry in nums one time, starting at index 1
- assign the entry value to entry + prior entry
- return vector

*/


class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        for (int i = 1; i < nums.size(); i++)
            nums[i] = nums[i] + nums[i-1];
        
        return nums;
    }
};