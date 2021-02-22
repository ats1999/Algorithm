# 1 - Count numbers
> Two passes
```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c0=0,c1=0,c2=0;
        
        // count number of 0's, 1's and 2's
        for(int el:nums){
            if(el == 0)
                c0++;
            else if(el == 1)
                c1++;
            else c2++;
        }
        
        // put  0's, 1's and 2's according to count
        
        // put 0's
        for(int i=0; i<c0; i++){
            nums[i] = 0;            
        }
        
        // put 1's
        for(int i=c0; i<(c0+c1); i++){
            nums[i] = 1;            
        }
        
        // put 2's
        for(int i=(c0+c1); i<(c0+c1+c2); i++){
            nums[i] = 2;            
        }
    }
};
```


