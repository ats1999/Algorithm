https://afteracademy.com/problems/recursive-insertion-sort

```cpp
/**
 * @type of arr: integer array
 * @return type: integer array
 */
class Solution {
public:
    void sortOne(vector<int>& ar,int idx){
    	if(idx<1 || ar[idx-1]<ar[idx])
            return;
        swap(ar[idx-1],ar[idx]);
        sortOne(ar,--idx);
    }
    
    void recursiveSort(vector<int>& ar,int idx){
    	if(idx >= ar.size()) 
            return;
        
        sortOne(ar,idx);
        recursiveSort(ar,++idx);
    }
    
	vector<int> recursiveInsertionSort(vector<int>& arr) {
        recursiveSort(arr,0);
        return arr;
	}
};
```
