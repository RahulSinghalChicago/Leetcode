/*
Constraints
- valid IPv4 address
- return the same string replacing each period with brackets around it

- O(n) for space and time

Diagram
1.1.1.1
  i 
1[.]1.1.1



pCode
- create return string
- create const defanged string [.]

- loop through our address by character
- if character is a period, then add the defanged string
- else add the character

- return the new string

*/


class Solution {
public:
    string defangIPaddr(string address) {
        string result;
        string defanged_string = "[.]";
        
        for (int i = 0; i < address.length(); i++)
            if (address[i] == '.')
                result += defanged_string;
            else
                result += address[i];
        
        return result;   
    }
};