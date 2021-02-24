```cpp
int maxSubArray(const vector<int> &A) {
    int sum=0,max_sum=A[0],len=A.size();
    
    for(int i=0; i<len; i++){
        sum = sum + A[i];
        max_sum = max(sum,max_sum);
        
        if(sum<0) sum = 0;
    }
    return max_sum;
}
```
