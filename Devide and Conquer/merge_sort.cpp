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
void merge(int ari[],int left[],int right[],int size,int l,int r){
	int i=0,j=0,k=0;
	int ar[5];
	// merge two array
	// at every iteration, insert minimum first element of the both array
	for(;i<size;i++){
		
		if(j<l&&k<r){
			if(left[j]<right[k]){
				
				ar[i]=left[j];
				cout<<"i j k: "<<i<<" "<<j<<" "<<k<<endl;
				cout<<"Left[]: j"<<left[j]<<" "<<ar[i]<<endl;
				j++;
			}else{
				ar[i]=right[k];
				cout<<"i j k: "<<i<<" "<<j<<" "<<k<<endl;
				cout<<"right[]: k"<<right[k]<<" "<<ar[i]<<endl;
				k++;
			}
		}else break;
	}
	
	cout<<"Breaked\n";
	// after insertion might be one array left with some element then insert it into ar[]
	for(;j<l;j++){
		ar[i]=left[j];
		i++;
	}
		
	for(;k<r;k++){
		ar[i]=left[k];
		i++;
	}
} // end of merge()

/**
* This function performes merge sort on the given array.
* @param ar[] input array nee to be sorted. 
* @param size: size of ar[]. 
*/
void mergeSort(int ar[],int size){
	// base case
	if(size<=1)
		return;
	
	// make two auxilary array and store half of the lements in both array
	int mid=size>>1; // mid=size/2
	int left[mid];
	int right[size-mid];
	
	// copy element in both array from ar[]
	int i=0;
	for(;i<mid;i++)
		left[i]=ar[i];
		
	for(;i<size;i++)
	 	right[i]=ar[i];
	
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
    int ar[5],left[2]={1,8},right[3]={2,45,65};
    
    merge(ar,left,right,5,2,3);
    
    for(int i=0;i<5;i++)
    	cout<<ar[i]<<" ";
	return 0;
}

