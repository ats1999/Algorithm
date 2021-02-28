
# Sorting intervals

```cpp
class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> >& intervals)
    { 
        vector<vector<int> > result;
        int len = intervals.size();
        
        // sort array of intervals by start interval
        sort(intervals.begin(), intervals.end(), [](auto a, auto b) {
            return a[0] < b[0];
        });
        
        // initialize first interval
        int l = intervals[0][0], r = intervals[0][1];

        for (int i = 1; i < len; i++) {
            if (intervals[i][0] > r || intervals[i][1] < l) {
                // if current interval is out of range
                // push previously calculated interval into result
                vector<int> cur;
                cur.push_back(l);
                cur.push_back(r);
                result.push_back(cur);
  
                // initialize l and r with current interval, because previous interval is out of range
                l = intervals[i][0];
                r = intervals[i][1];
            }
            else {
                // if current interval is not out of range
                // initialilze l and r with the biggest interval by merging previous interval and current interval
                l = min(l, intervals[i][0]);
                r = max(r, intervals[i][1]);
            }
        }
        
        // last interval is not pushed by the for loop
        // consider input [[1,2]]
        vector<int> cur;
        cur.push_back(l);
        cur.push_back(r);
        result.push_back(cur);
        
        return result;
    }
};
```

**T.C** O(NlogN) 

> Time to sort array - (merge sort)
> 
**A.S** O(N)

> Used by sorting algorithm - (merge sort)
> 

### Explained
```cpp
// input
[[1,3],[20,60],[8,10],[10,18]]

// after sorting
[[1,3],[8,10],[10,18],[20,60]]

// initially 
l = 1;
r = 3;
result = [];



// pass 1
// [8,10] is out of range
// put [8,10] into result
l = 8;
r = 10;
result = [[1,3]];

// pass 2
// [10,18] is inside range
l = 8;
r = 18;
result = [[1,3]];

// pass 3
// [20,60] is out of range
// put [8,18] into result
l = 20;
r = 60;
result = [[1,3],[8,18]];

// put [20,60] into the result after for loop
result = [[1,3],[8,18],[20,60]];
```
