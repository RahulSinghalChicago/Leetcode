'''
constraints
edge case, no parens, just return
O(n) time
O(1) space

diagram
(()())(())
1212101210
()() ()
()()()

(()()) (()) (()(()))
()()()()(())

()()

pcode
open_count = 0
result = ""
loop through each character
- increment open_count if it's open parens
  - if open_count > 1
    - append character to result
- decrement open_count if it's closed parens
  - if open_count > 0
    - append character to result
'''

class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        open_count = 0
        result = ""
        for x in s:
            if x == "(" : 
                open_count += 1
                if open_count > 1 : result += x
            if x == ")" : 
                open_count -= 1
                if open_count > 0 : result += x
        return result