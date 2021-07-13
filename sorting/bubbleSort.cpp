//============================================================================
// Name        : bubbleSort.cpp
// Author      : Rahul
// Version     : 2.0
// Copyright   : Everyone freely can use and distribute it.
// Description : TO Sort a array of numbers.
//============================================================================



/**
 * This function is used to sort input array and return sorted array. 
 * @param int ar[]: input aarray.
 * @param int n: size of array.
 * @return int ar[]: sorted array.
 * Time complexity:
 *                  Worst case: O(n^2)
 *                  Avg case  : O(n^2)
 *                  Best case : O(n)
 * Space complexity:
 *                  In all case: O(1)
 */
int *bubbleSort(int *ar,int n){
    bool flag=false; // to test wheater array is already sorted.
        // traverse the hole array
        for(int i=0;i<n;i++){
            // swap if needed
            for(int j=0;j<n-i-1;j++){
                if(ar[j]>ar[j+1]){
                    flag=true;
                    swap(ar[j],ar[j+1]);
                }   
            }
            // check if array is already sorted.
            if(!flag)
                break;
        }
        return ar;
}
