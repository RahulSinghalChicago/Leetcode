/*
Diagram

j = "aA"
     
s = "aAAbbbb"
3           i
cnt = 1+1+1 = 3

"z"
"ZZ"
0

Constraints
- jewels list once (n)
- stones list once (m)
O(n+m) runtime
O(n) space

pCode
- int count = 0
- Set j

- Loop through jewels
- add each character to our Set j

- Loop through stones
- check if stones[i] is in Set j, then increment count

- return count
*/


class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        std::set<char> j;
        
        for (int i = 0; i < jewels.length(); i++)
            j.insert(jewels[i]);

        for (int i = 0; i < stones.length(); i++)
            if (j.count(stones[i])) count++;
        
        return count;
    }
};