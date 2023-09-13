'''
n buildings
int array of heights, same as n
ocean to the right
if all to right are smaller, it has an ocean view

return 0-indexed sorted list having ocean view

loop forwards

brute force, n^2 solution, check this entry against all to the right
then check the next one against all to the right

instead start from the end of the heights list
keeping track of the highest building seen,
if this building is taller, then add index to ocean view

at the end reverse the list
Time O(n)
Aux Space O(n)

'''

class Solution:
    def findBuildings(self, heights: List[int]) -> List[int]:
        max_seen = 0
        results = []
        for index in range(len(heights)-1, -1, -1):
            if heights[index] > max_seen:
                results.append(index)
                max_seen = heights[index]
        return reversed(results)