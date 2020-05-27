//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description :
// T.C         : O()
// A.S         : O()
//============================================================================
#include<bits/stdc++.h>
using namespace std;
#include "../print.h"
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

/**
 * This function generates permutation.
 * @param ar input array
 * @param choosen bool array keep track of chooses item
 * @param permutation contains result
 * @param currentPermutation contains current result
 * @param n size of ar[] and choosen[]
 * @return vector<vector<int>> containing all permutation. 
 */

void generatePermutation(int ar[],vector<vector<int>>&permutation,vector<int>&currentPermutation,bool choosen[],int n){
	// process permutation
	if(currentPermutation.size()==n){
		permutation.push_back(currentPermutation);
	}else{
		// for every element we have two choices, either we'll include current 
		// element or not. 
		for(int i=0;i<n;i++){
			// if current element is included
			if(choosen[i])
				continue;
			
			// include current element
			choosen[i]=true;
			currentPermutation.push_back(ar[i]);

			// recur
			generatePermutation(ar,permutation,currentPermutation,choosen,n);

			// exclude current element
			choosen[i]=false;
			currentPermutation.pop_back();
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
	vector<int>currentPermutation;
	int ar[]={1,2,3,4};
	bool choosen[]={false,false,false,false,false,false,false};
	generatePermutation(ar,permutation,currentPermutation,choosen,4);
	for(auto it:permutation){
		for(int i:it)
			cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}