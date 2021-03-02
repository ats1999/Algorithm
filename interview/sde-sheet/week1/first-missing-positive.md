# Using sorting
input
```cpp
[3,4,-1,1]
```
 
After sorting
```cpp
[-1,1,3,4]
```

Number **2** is missing b/w 1 and 3.

**T.C** O(NlogN) - time to sort...

**A.S** O(N) used by sorting algorithm

# By moving all i<=n to it's correct position

For all `i` in `nums`, move `nums[i]` at `nums[nums[i]-1]` if possible.

For example:

Input
```cpp
[3,5,4,2,7]

// after shift
[3,2,3,4,5];

// here first number, 3 is having incorrect position
So, answer will be 1
```
```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for(int i=0; i<len; i++){
            int cur = nums[i];
            while(cur>0 && cur<=len && nums[cur-1] != cur){
                int temp = nums[cur-1];
                nums[cur-1] = cur;
                cur = temp;
            }
        }
        
        for(int i=0; i<len; i++){
            if(nums[i] != i+1) return i+1;
        }
        return len+1;
    }
};
```
