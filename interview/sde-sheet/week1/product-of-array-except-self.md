https://leetcode.com/problems/product-of-array-except-self/

# Brute force approach
```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int>result(len);
        
        for(int i=0; i<len; i++){
            long long p = 1;
          
            // get products before i
            for(int j=0; j<i; j++)
                p *= nums[j];
            
            // get products after i
            for(int j=i+1; j<len; j++)
                p *= nums[j];
            result[i] = p;
        }
        return result;
    }
};
```
