//============================================================================
// Name        : quick_select.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Find kth order statics from the given array. 
//             - Ex:- find kth smallest or largest element from the given array. 
// T.C         : O(n)
// A.S         : O(1)
//============================================================================
#include<bits/stdc++.h>
using namespace std;
/**
* Find pivot such that all elements left side of pivot are less than pivot, elements that are right side of pivot should greater that pivot.
* @param ar[]: inpuut array
* @param n: sizee of the array.
* @return index of pivot
*/
int pivot(int ar[],int start,int n){
	// select first element as pivot
	int pivot=ar[start];
	int k=start+1,j=n;
	
	// move k forward untill a number greater than pivot found
	while(ar[k]<pivot&&k<j)
		k++;
		
	// move j backward untill a number smaller than k found
	while(ar[j]>pivot&&j>0)
		j--;
	
	while(j>k){
		// swap both index element
		swap(ar[j],ar[k]);
		// move k forward untill a number greater than pivot found
		while(ar[k]<pivot&&k<=j)
			k++;
		// move j backward untill a number smaller than k found
		while(ar[j]>pivot&&j>0)
			j--;
	}
	// finally swap pivot with it's right index. 
	swap(ar[start],ar[j]);
	return j;
}
/** 
 * This function finds kth smallest or greater element from the array in Nlog(n) time.
 * @param {ar}: input array
 * @param {k} : order of the input
 * @param {start} : start index of the array
 * @param {end}  : last index of the array
 */
int quickSelect(int ar[],int k,int start,int end){
    int pivotIndex=pivot(ar,start,end);
    if(pivotIndex==k-1)
        return ar[pivotIndex];
    if(pivotIndex>k-1)
        return quickSelect(ar,k,start,pivotIndex-1);
    else return quickSelect(ar,k,pivotIndex+1,end);
    return -1;
}
// driver code
int main(){
	cout<<"Started\n";
	int ar[10]={1,2,0,456,89,53,0,4,7,8};
    cout<<endl;
    cout<<quickSelect(ar,1,0,10)<<endl; //0
    cout<<quickSelect(ar,5,0,10)<<endl; //4
    cout<<quickSelect(ar,9,0,10)<<endl; //89
    cout<<quickSelect(ar,10,0,10)<<endl; // 456
	return 0;
}