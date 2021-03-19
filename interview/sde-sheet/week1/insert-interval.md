Input
```cpp
// intervals
[[1,2],[3,5],[6,7],[8,10],[12,16]]

// new interval
[4,8]
```
# 1
Check if new interval can be merged or not.
> We can do this check in **O(logN)** time using technique of binary search (input is sorted by start interval point).
> 
If it can be merged, then merge and return the answer.
If it is not possible to merge , then push **new interval** at the end of the vector and sort the vector by start position.

**T.C** O(logN) + O(NlogN)
> Time taken to search  +  sort
# 2
>If it is not possible to merge , then push **new interval** at the end of the vector and sort the vector by start position.

Insted of sorting, we can bring the new interval at it's correct position by shifting intervals one by one.

**T.C** O(logN) + O(N)
> Time taken to search  +  place new interval
