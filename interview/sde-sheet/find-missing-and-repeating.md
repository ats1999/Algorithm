# Two pass
1. find repeting number
2. sum of array elements `(required to calculated missing number)`

We can use same optimized cycle detection method according to this https://github.com/ats1999/Algorithm/blob/master/interview/sde-sheet/sort_colors.md.

Once we found the repeating number then we can find mission number using simple math.

```cpp
// Input
[1,3,2,3]

// we can find repeating number by above algorithm

repetNum = 3; //repeating number

totalSum = 10; // n(n+1)/2 - math

curSum = 9; // sum of elements of array 

missingNum = totalSum-(curSum-repetNum);

// ----- //
missingNum = 10-(9-3) = 4
```
26
**T.C**: O(n)
**A.S**: O(1)
