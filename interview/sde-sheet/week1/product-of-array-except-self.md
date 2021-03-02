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

# Count number of zero
In the given array, numbers of 0's could be
```cpp
[1,2,3]
0 -> no zero in the array

[4,0,5]
1 -> one zero in the array

[4,0,8,0]
N -> more then one zero in the array
```
Output
```cpp
// no zero
[1,2,3] -> [6,3,2]

// one zero
// at zero's position, put product of all elements except zero
[4,0,5] -> [0,20,0]

// N zero
// all products will be zero
[4,0,8,0] -> [0,0,0,0]
```

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        long long p = 1,c0=0;
        for(int i:nums){
            if(i==0) 
                c0++;
            else p*=i;
        }
        
        if(c0>1){
            // make all 0
            for(int i=0;i<len;i++)
                nums[i] = 0;
        }else if(c0==1){
            // make all zero except where was zero
             for(int i=0;i<len;i++){
                 if(nums[i] == 0)
                     nums[i] = p;
                 else nums[i] = 0;
             }
        }else{
             // there is no zero in input
             for(int i=0;i<len;i++) 
                 nums[i] = p/nums[i];
        }
        
        return nums;
    }
};
```

# Without division operator
https://leetcode.com/problems/product-of-array-except-self/solution/
