//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Find next permutation until it is pissible. If array is sorted in decending order then it is not possible to find next permutation. 
// T.C         : O(n*n!)
// A.S         : O(n*n!) if we store result O(n) otherwise. 
//============================================================================
#include<bits/stdc++.h>
using namespace std;
#include "../print.h"
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)


/**
 * Apply binary search, because array is reversed sorted.
 * This function finds the element in the range that is just greter than val.
 * @param ar[] input array
 * @param val input value that is to be searched.
 * @param start start index.
 * @param end end index.
 * @return index of found element. 
 */
// Utility function !
int indexToSwap(int ar[],int val,int start,int end){
	// if there is only one element in the range. 
	if(start==end)
		return start;

	int index=0;
	// till start less than end
	// apply binary search
	while(start<=end){
		int mid=(start+end)/2;

		if(ar[mid]>val){
			// if current mid element is greter than val then keep it's index
			index=mid;
			start=mid+1;
		}else{
			end=mid-1;
		}
	}
	return index;
}
/**
 * This function generates permutation iteratively by finding next permutation.
 * @param ar input array
 * @param choosen bool array keep track of chooses item
 * @param permutation contains result
 * @param currentPermutation contains current result
 * @param n size of ar[] and choosen[]
 * @return vector<vector<int>> containing all permutation. 
 */
void nextPermutation(int ar[],vector<vector<int>>&permutation,int n){
	int i=n-1;
	bool flag=false;
    while(!flag){
		// process permutation
		vector<int>v(ar,ar+n);
		permutation.push_back(v);

		while(i>0&&ar[i-1]>ar[i])
			i--;
	
		// if i is less than zero then next permutation is not possible. 
		if(i<=0)
			flag=true;
		else {
			// get minimum index of the element to swap
			int minIndex=indexToSwap(ar,ar[i-1],i,n-1);
			// swap elements
			swap(ar[i-1],ar[minIndex]);
			
			// sort after the swaped element
			sort(ar+i,ar+n);
			i=n-1;
		}
	}
}
// driver code
int main(){
	cout<<"Started\n";
	// I/O
	IOS;
    #ifndef ONLINE_JUDGE 
	    // For getting input from input.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin); 
	    // Printing the Output to output.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
    vector<vector<int>>permutation;
	int ar[]={0,1,2,3};
	nextPermutation(ar,permutation,4);
	for(auto it:permutation){
		for(int i:it){
			cout<<i<<" ";
		}
		cout<<endl;
	}
	return 0;
}