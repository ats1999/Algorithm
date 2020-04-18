//============================================================================
// Name        :selectionSort .cpp
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
 *                  Best case : O(n^2)
 * Space complexity:
 *                  In all case: O(1)
 */
int *selectionSort(int *ar,int n){
    int minVal=0;
    // incase when array has one or no element.
    if(sizeof(ar)/sizeof(ar[0])<1)
        return ar;
    for(int i=1;i<n;i++){
        // find samllest number from remaning array
        int *ptr=min_element(ar+i,ar+n);
        // if swap needed
        if(ar[i-1]>*ptr){
            swap(ar[i-1],*ptr);
        }
    }
    return ar;
}
