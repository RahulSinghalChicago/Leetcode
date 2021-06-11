/*

Constraints
1 <= name.length <= 1000
1 <= typed.length <= 1000
name and typed contain only lowercase English letters.

edge case: name.length > type.length, return false
edge case: consecutive repeating characters in name, not reflected in typed

time O(n + m)
space O(1)



Diagram

"saeed"
    i 
"ssaaedd"
      j
      
edge case: check current i with current j && prior i with current j, increment j


"leelee"
  i 
"lleeelee"
   j
 
pCode:
- index j for typed starts at 0
- index i for name starts at 0
- if name.length > typed.length return false

- loop through characters i and j while still valid
- if name[i] == typed[j] then match, increment counters and move to next loop
- else if no match, check prior i value (if valid) with current j value for match, increament j only
- 

*/


class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int j = 0;
        int i = 0;
        
        if (name.length() > typed.length())
            return false;
        
        while (i < name.length() || j < typed.length()) {
            if (i < name.length() && j < typed.length() && name[i] == typed[j]) {
                j++;
                i++;
                continue;
            } 
            else if (i > 0 && name[i-1] == typed[j]) {
                j++;
                continue;
            } 
            else
                return false;
        }
        
        if (j < typed.length())
            return false;
        
        return true;   
    }
};