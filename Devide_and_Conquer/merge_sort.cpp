//============================================================================
// Name        : merge_sort.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Implement merge sort algorithm.  
// T.C         : O(nlog(n))
// A.S         : O(n)
//============================================================================
#include<bits/stdc++.h>
using namespace std;
/**
* This function merge two unsorted array (left[] and right[]) in sorted array ar[]
* @param ar[]: array are merged stored in this array
* @param left[]: left array.
* @param right[]: right array.
* @param size: size of ar[].
* @param l: size of left[].
* @param r: size of right[].
*/
void merge(int ar[],int left[],int right[],int size,int l,int r){
	int i=0,j=0,k=0;
	// merge two array
	
	// at every iteration, insert minimum first element of the both array
	// Once any array fully traversed then stop iteration
	for(;i<size;i++){
		if(j<l&&k<r){
			if(left[j]<right[k]){
				ar[i]=left[j];
				j++;
			}else{
				ar[i]=right[k];
				k++;
			}
		}else break;
	}
	
	// after insertion might be one array left with some element then insert it into ar[]
	
	// if left array has some element then insert into ar[]
	for(;j<l;j++){
		ar[i]=left[j];
		i++;
	}
	
	// if right array has some element then insert it into ar[]	
	for(;k<r;k++){
		ar[i]=right[k];
		i++;
	}
} // end of merge()

/**
* This function performes merge sort on the given array.
* @param ar[] input array nee to be sorted. 
* @param size: size of ar[]. 
*/
void mergeSort(int ar[],int size){
	// If ar is large enough then only processed further...
	if(size<=1)
		return;
	
	// make two auxilary array and store half of the lements in both array
	int mid=size>>1; // mid=size/2
	// left part of the array
	int left[mid]; 
	// rght part of the array
	int right[size-mid]; 
	
	// copy element in both array from ar[]
	int i=0,j=0;
	for(;i<mid;i++)
		left[i]=ar[i];
		
	for(;i<size;i++){
		right[j]=ar[i];
		j++;
	}
	// recursively call mergeSort() for both array for further division
	mergeSort(left,mid);
	mergeSort(right,size-mid);
	
	// merge both array
	merge(ar,left,right,size,mid,size-mid);
	
} // end of mergeSort()


// driver code
int main(){
	// fast I/O
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<"Start\n";
    int ar[10]={2,8,89,0,123,12,1,4,6,2};
    
    cout<<"Input...\n";
    for(int i=0;i<10;i++)
    	cout<<ar[i]<<" ";
    	
    mergeSort(ar,10);
    
    cout<<"\n\n\nOutput...\n";
    for(int i=0;i<10;i++)
    	cout<<ar[i]<<" ";
	return 0;
}

