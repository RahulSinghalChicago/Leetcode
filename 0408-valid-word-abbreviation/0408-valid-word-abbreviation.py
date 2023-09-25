'''

loop through each character while to check if it's alpha or numeric

split that chunk into into a dictionary


'''

class Solution:
    def validWordAbbreviation(self, word: str, abbr: str) -> bool:
        match = []
        
        idx = 0
        prior = 0
        while idx < len(abbr):
            while idx < len(abbr) and abbr[idx].isalpha():
                idx += 1
            if idx > prior:
                match.append(("A", abbr[prior:idx]))
                prior = idx
                continue
            if abbr[idx] == "0":
                return False
            while idx < len(abbr) and abbr[idx].isdigit():
                idx += 1
            if idx > prior:
                match.append(("N", int(abbr[prior:idx])))
                prior = idx
                
        # print(match)
        left = 0
        right = 0
        for action, value in match:
            if right > len(word):
                # print(right, len(word))
                return False
            if action == "A":
                right += len(value)
                # print(left, right, word[left:right], value)
                if word[left:right] != value:
                    return False
                left = right
                continue
            if action == "N":
                left += value
                right = left

        if right != len(word):
            # print(right, len(word))
            return False
        
        return True
                
                
                