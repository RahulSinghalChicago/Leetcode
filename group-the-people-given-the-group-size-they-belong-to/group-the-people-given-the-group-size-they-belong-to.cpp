/*
Constraints
- exactly one group per person
- every person in a group
- at least 1 valid solution
- up to 500 people
- 1 <= groupSizes[i] <= n

- time O(n)
- space O(n)


[3,3,3,3,3,1,3]
 0 1 2 3 4 5 6

[[5],[0,1,2],[3,4,6]]
- 5 has to be in a group by themselves
- everyone else is in a group of 3, therefore many possible solutions


[2,1,3,3,3,2]
 0 1 2 3 4 5
 
map [ [2: 0,5] 
      
      
    ]

results [
         [1]
         [2,3,4]
        ]

[[1],[0,5],[2,3,4]]
            
            
- each group size will have a factor of that group size possible values
- above 1 set of 2s or 2 sets of 3 or 1 set of 3

pcode:
- create map hash_map<int, vector<int> >
- create result array

- loop through groupSizes by i
- hash_map[groupSizes[i]].push(i)
- if groupSizes[i] = map[groupsizes[i]] // then that's a complete group
-    add to result
-    reset group

- return results
*/


class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int> > hash;
        vector<vector<int> > results;
        
        
        for(int i = 0; i < groupSizes.size(); i++) {
            hash[groupSizes[i]].push_back(i);
            
            if (hash[groupSizes[i]].size() == groupSizes[i]) {
                results.push_back(hash[groupSizes[i]]);
                hash[groupSizes[i]].clear();
            }
            
        }
        
        return results;
    }
};