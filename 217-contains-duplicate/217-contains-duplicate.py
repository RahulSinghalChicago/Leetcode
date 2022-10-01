"""
Constraint

Diagram

pCode
loop through nums
check if exists in hash
  yes: return false
  no:  add to hash
return true

Code

"""


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        unique = set()
        for i in nums:
            if i in unique:
                return True
            else:
                unique.add(i)
        return False
    
