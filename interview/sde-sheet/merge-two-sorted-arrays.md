# M1
Sort the first array by comparing elements from another array. After swaping sort the 2nd array.

```cpp
class Solution{
    public:
        void merge(int ar1[], int ar2[], int n, int m) 
        { 
            for(int i=0; i<n; i++){
                if(ar1[i]>ar2[0]){
                    swap(ar1[i],ar2[0]);
                    
                    // sort ar2
                    for(int j=1; j<m; j++){
                        if(ar2[j-1]>ar2[j]) swap(ar2[j],ar2[j-1]);
                        else break;
                    }
                }
            }
        } 
};
```
**T.C** O(n*m)
