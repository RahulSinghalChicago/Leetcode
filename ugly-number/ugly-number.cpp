/*
Constraints
- return true or false
- given n
- return true if prime factors are only 2, 3, 5
- edge case of 1, return true

O(n) space
O(lg n) time


Diagramming
N is even, divisible by 2 

                  14
          /               \
      7[2,3,5]             14[3,5]
       /    \              /     \
    PRIME                NO DIVISOR 

- could memo to decrease time

pCode
- if n % 2 != 0 (same for 3 or 5), return false
- if n is 1 or -1 return true
- if n is 2,3,5 return true

- result = false

- result = result || recurse calling isUgly(n / 2) if n % 2 == 0
- result = result || recurse calling isUgly(n / 3) if n % 3 == 0
- result = result || recurse calling isUgly(n / 5) if n % 5 == 0

return result
*/

class Solution {
public:
    bool isUgly(int n) {
        int temp = n;
        
        if (n == 1) return true;
        if (n == 0) return false;
        
        
        while (temp % 2 == 0)
            temp /= 2;
        while (temp % 3 == 0)
            temp /= 3;
        while (temp % 5 == 0)
            temp /= 5;
        
       cout << temp << endl;
        
        return temp == 1;
        
        
    }
};