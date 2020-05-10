//============================================================================
// Name        : quick_sort.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description :
// T.C         : ---------------------
//			   : Best case:= O(lon(n))
//			   : Worst case:= O(n^2)
// A.S         : O(1)
//============================================================================
#include<bits/stdc++.h>
using namespace std;
/**
* Function to sort an array using quick sort algorithm. 
* @param ar: input array
* @param size : size of the array
*/

void quickSort(int ar[],int start,int end){
	// choose pivot
	int pivot=a[0];
	int 
	i=start,j=end-1;
	
	while(!j<i){
		// moke i forward till ar[i]<pivot
	while(ar[i]<pivot)
		i++;
	// moke j backwordd while ar[j]>p
	while(ar[j]>pivot)
		j--;
		
	swap(ar[j],ar[i]);
	}
	// if i and j crossed then replace pivot with j
	swap(ar[0],ar[j]);
	
	quickSort(ar,start,i);
	quickSort(ar,i,end);
}
// driver code
int main(){
	// fast I/O
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	return 0;
}

