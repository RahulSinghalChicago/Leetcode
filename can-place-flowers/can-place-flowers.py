'''
constraints:
from 1 to 2 * 10^4
need 1 space between
incoming n is 0 to length of bed

time O(n)
space O(1)

diagram:

ex1.
[1,0,X,0,1]
n = 1
true
3 zeroes in a row, allows 1 to be added

ex2.
[1,0,0,0,1]
n = 2
false

edge case
if first two or last two positions are zero, then we can add one

[1,0,0,0,1]
       i
       
[0]

[1,0,0,1]

pcode

loop through flowerbed from 0 to n-1
- if i=1 and first two are zero then 
  - decrement n
  - update position 0 to 1
- if i>=2 and last 3 indexes are zero then 
  - decrement n
  - update index i-1 to 1
- if i == n-1 and last two are zero then 
  - decrement n

return false

'''

class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        len_fb = len(flowerbed)
        
        if (len_fb == 1 and flowerbed[0] == 0 and n <= 1) : return True
        
        
        for i in range(len_fb):
            if (i == 1 and sum(flowerbed[0:2]) == 0):
                flowerbed[0] = 1
                n -= 1
            elif (i >= 2 and sum(flowerbed[i-2:i+1]) == 0):
                flowerbed[i-1] = 1
                n -= 1
            elif (i == len_fb - 1 and sum(flowerbed[i-1:i+1]) == 0):
                n -= 1
            if (n <= 0):
                return True
        
        return False