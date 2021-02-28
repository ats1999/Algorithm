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
# 2- Two pointers approach 
```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
       int l=0,r=nums.size()-1;
       // IDEA
       // move all 2's at end
       // move all 0's at first
       // 1's will be automatically sorted
       while(l<r){
           if(nums[l]==2){
               // move 2 at the end if possible 
               if(nums[r]!=2)
                   swap(nums[l],nums[r]);
               else 
                   {
                   while(nums[r]==2 && r>l) r--;
                   swap(nums[l],nums[r]);
               }
           }
           
           if(nums[l] == 1){
               // find next 0
               // and replace the nums[l] with the zero
               // this will brings 0 in front of 1
               int zero = l+1;
               while(zero < r && nums[zero] != 0) zero++;
               
               if(nums[zero] == 0) 
                   swap(nums[l],nums[zero]);
           }
           
           l++;
       } 
    }
};
```

