https://leetcode.com/problems/pascals-triangle/

# Brute force
```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result;
        if(numRows == 0)
            return result;
        
        result.push_back(vector<int>{1});
        
        for(int i=2; i<=numRows; i++){
            vector<int>cur(i);
            
            // boundary values of the row
            cur[0] = 1, cur[i-1] = 1;
            
            // put rest of the values
            for(int j=1; j<i-1; j++){
                cur[j] = result[i-2][j-1] + result[i-2][j];
            }
            result.push_back(cur);
        }
        return result;
    }
};
```
