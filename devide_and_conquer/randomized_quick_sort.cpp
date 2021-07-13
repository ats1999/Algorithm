//============================================================================
// Name        : randomized_quick_sort.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Perform quick sort on the given input array using randomization. 
// T.C         : ---------------------
//			   : Best case:= O(Nlon(N))
//			   : Worst case:= O(n^2)
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
    srand(time(0));// random number 
    int randomIndex=rand()%(n-start)+1;
	int pivot=ar[start+randomIndex];
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
* Function to sort an array using quick sort algorithm. 
* @param ar: input array
* @param start : start index of the array
* @param end   : last index of the array
*/

void quickSort(int ar[],int start,int end){
	// if array size of large enough to sort then only go further
	// otherwise return 
	// to sort array it's size must be greater than 1
	if((end-start)<=1)
		return;
	int pivotIndex=pivot(ar,start,end);
	// sort first half of the array
	quickSort(ar,start,pivotIndex-1);
	// sort econd half of the array
	quickSort(ar,pivotIndex+1,end);
}

// driver code
int main(){
	// fast I/O
	cout<<"Start\n";
    int ar[10]={1,2,0,456,89,53,0,4,7,8};
    cout<<endl;
    quickSort(ar,0,10);
	
	for(int i=0;i<10;i++)
		cout<<ar[i]<<" ";
	return 0;
}

