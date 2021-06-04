#include <stack>

/*
"([)]"
   i 


[
(
s
false


return false as soon we see something invalid
return true at the end

"{[]}"
     i
true

s
summary add open brackets 

()[]{}
  i

popped value = 

[
s
true

time: O(n)
space: O(n)


pCode
- create a stack


- loop through string
- check current character
- if current is open bracket list, add to stack
- if current is not in open bracket list, pop from stack
- if the stack is empty or doesn't match current, return false

- return true

*/


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char c, pv;
        
        if (s.length() < 2) return false;
        
        for (int i=0; i<s.length(); i++) {
            c = s[i];
            if (c == '(' || c == '[' || c == '{')
                st.push(c);
            else {
                if (st.empty()) return false;
                
                pv = st.top();

                switch (pv) {
                case '(':
                    if (c != ')') return false;
                    break;
                case '{':
                    if (c != '}') return false;
                    break;
                case '[':
                    if (c != ']') return false;
                    break;
                }
                st.pop();
            }
        }
        
        if (st.empty())
            return true;
        
        return false;
    }
};