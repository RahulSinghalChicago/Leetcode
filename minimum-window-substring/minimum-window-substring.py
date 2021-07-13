'''
strings of 1 to 10^5
time O(n+k)
space O(1)

hash the chars in K
hash the chars in N slice

ABC
ADOBECODEBANC
         i     
            j

pcode
def contains_hash
def makeHash
def addHash
def remHash

min_start = 0
min_end = len(N)
hashK 
hashN
loop until i is at the end of N
  increment j until slice N hash contains hash K or j is at end
  increment i by 1 while valid
  if contains hash and (j - i < min_end - min_start) update min*

  
'''

def contains_hash(hashN, hashK):
    for key in hashK:
        if (key not in hashN or hashN[key] < hashK[key]):
            return False

    return True

def makeHash(strA):
    hashA = dict()
    for c in strA:
        if c not in hashA : hashA[c] = 0
        hashA[c] += 1
    return hashA

def addHash(hashA, c):
    if c not in hashA : hashA[c] = 0
    hashA[c] += 1

def remHash(hashA, c):
    hashA[c] -= 1

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        
        n = s
        k = t
        lenN = len(n)
        lenK = len(k)
        min_start = 0
        min_end = lenN

        # edge case
        if lenN < lenK : return ""
        
        hashK = makeHash(k)
        hashN = makeHash(n[:lenK])
        i = 0
        j = lenK - 1
        exists = False

        while (i < lenN):
            # increment j until slice N hash contains hash K or j is at end
            while (not contains_hash(hashN, hashK) and j < lenN - 1):
                j += 1
                addHash(hashN, n[j])

            # increment i while valid
            while (contains_hash(hashN, hashK)):
                remHash(hashN, n[i])
                if (not contains_hash(hashN, hashK)):
                    addHash(hashN, n[i])
                    break
                i += 1

            # if contains hash and (j - i < min_end - min_start) update min*
            if (contains_hash(hashN, hashK) and j - i < min_end - min_start):
                min_start, min_end = i, j
                exists = True

            # increment i by 1
            remHash(hashN, n[i])
            i += 1

        if not exists : return ""
        return(n[min_start:min_end+1])


        