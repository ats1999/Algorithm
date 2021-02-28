# Using hashing
Store all numbers into set or hashmap which support O(1) operation.

Then iterate from 1 to n and check if it is persent into set or not. If it is not in the set then it the missing number.

**T.C** O(n)

**A.S** O(n) - set elements

# Using sorting

Input
```cpp
[4,3,2,7,8,2,3,1]
```
After sorting 
```cpp
[1,2,2,3,3,4,7,8]
```
You can see there a gap of more than **1** b/w **4** and **7** of `(7-4)` is **3**.

Then we can clearly say than there is some missing numbers b/w 4 and 7 which are...
```cpp
4+1 = 5;
4+2 = 6;
```
**T.C** O(NlogN) - time to sort
**A.S** O(N)
