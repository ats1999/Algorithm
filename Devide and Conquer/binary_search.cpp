//============================================================================
// Name        : binary_search.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description :
// T.C         : O(log(n))
// A.S         : O(1)
//============================================================================
#include<bits/stdc++.h>
using namespace std;
/**
* This function finds a number from given array
* @param ar: input array
* @param key: number is to find
* @param size: size of the array
* @return index of the number if found, -1 otherwise
*/
int binary_search(int ar[],int key,int size){
	// base case
	// empty aray
	if(size==0)
		return -1;
	// initilize start,end and mid
	int start=0,end=size,mid=0;
		mid=(start+end)>>1;
	// if mid element is greater than key then search in the left of mid in array
	// if mid element is smaller than key then search in the right of mid in array  
	while(!start==end){
		// check mid element
		if(ar[mid]==key)
			return mid;
		
		// according to the condition search left side or right side of the array
		if(ar[mid]>key){
			end=mid-1;
			mid=(start+end)>>1;
		}else{
			start=mid+1;
			mid=(start+end)>>1;
		}
	}
	
	// element id not found return -1
	return -1;
}

/**
* Recursive binary search.
* @param ar: input array
* @param key: number is to find
* @param size: size of the array
* @return index of the number if found, -1 otherwise
*/
int binary_search(int ar[],int start,int end,int mid,int key){
	mid=(start+end)>>1;
	
	if(ar[mid]==key)
		return mid;
	
	if(start==end)
		return -1;
	
	if(ar[mid]>key)
		return binary_search(ar,start,mid,(start+mid)>>1,key);
	else return binary_search(ar,mid,end,(mid+end)>>1,key);
}


// driver code
int main(){
	// fast I/O
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<"*****************************************************************\n";
    
    int ar[]={1,2,3,5,6,8,9,89,100,110};  // 10 numbers
    cout<<binary_search(ar,0,10,5,0);
        cout<<"\n*****************************************************************\n";

	return 0;
}

