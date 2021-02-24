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

# Gap method
https://www.youtube.com/watch?v=hVl2b3bLzBw

https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/

```cpp
class Solution{
    public:
        int nextGap(int n,int m){
            return ceil((float)(n+m)/2);
        }
        void merge(int ar1[], int ar2[], int n, int m) 
        { 
            int gap = nextGap(n,m);
            do{
                // apply GAP i nfirst array
                for(int i=0; i+gap<n+m; i++){
                    if(i<n && i+gap<n){
                        // first array
                        if(ar1[i]>ar1[i+gap])
                            swap(ar1[i],ar1[i+gap]);
                    }else if(i<n && i+gap>=n){
                        // cross array
                        if(ar1[i]>ar2[i+gap-n])
                            swap(ar1[i],ar2[i+gap-n]);
                    }else {
                        // second array
                        if(i-n+gap>=m) break;
                        
                        if(ar2[i-n]>ar2[i-n+gap])
                            swap(ar2[i-n],ar2[i-n+gap]);
                    }
                }
                if(gap == 1) gap = 0;
                else
                    gap=ceil((float)gap/2);
            }while(gap!=0);
        } 
};
```

## FollowUp
Solve in the below link **Another method in O(m+n) time complexity:**

https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/
