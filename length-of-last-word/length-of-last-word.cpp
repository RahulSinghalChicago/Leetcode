/*

constraints
O(n) time
O(1) space


diagram
Hello World
     i


pcode
edge case, string has no letters
edge case, string has 1 word
edge case, string has spaces at end (not tested)
typical case, multiple words

result string = ""

loop int i = s.length, exit if see a space or start of string
- skip space characters
- result += s[i]

return result.length
*/


class Solution {
public:
    int lengthOfLastWord(string s) {
        string result = "";
        int len = s.length()-1;
        while (s[len] == ' ' && len > 0)
            len--;
        
        for (int i = len; i >= 0; i--) {
            if (s[i] == ' ') break;
            result += s[i];
        }
        return result.length();
    }
};