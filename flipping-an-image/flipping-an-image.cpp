/*

Constraints
- algo O(n^2)
- space O(1)

Diagram
[1,1,0]  [0,1,1]
 i
         [1,0,0]
              j       
1 0
0 1
1 0 do nothing

1 1
0 0 just invert

1
0 just invert


pCode
- loop through all rows
- sub loop from left to right and right to left
- case odd number n where i and j are the same, just invert
- case both same i and j then just invert
- case different i and j do nothing
- return updated image

*/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        
        for (int row = 0; row < n; row++)
            for (int i = 0, j = n-1; i <= j; i++, j--) {
                if (i == j) {               
                    cout << i << " " << j << endl;
                    image[row][i] = image[row][i] ? 0 : 1;
                } else if (image[row][i] == image[row][j]) {
                    image[row][i] = image[row][i] ? 0 : 1;
                    image[row][j] = image[row][j] ? 0 : 1;   
                }
            }
        
        return image;
    }
};