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
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

// methods
/*
1-  We can make use of sorting.
	First we'll make an auxlary array (temp). 
	Then we'll copy all elements from ar1 and ar2 into temp.
	Then we'll sort the temp. 
	
	T.C = O(NlogN) - if we use efficient sorting algorithm.
		= O(n + m + (n+m)log(n+m))
		- O(n) - time to copy first array into temp
		- O(m) - time to copy second array into temp
		- O((n+m)log(n+m)) to sort temp.
		
	A.S = O(N+M) - if we use efficient sorting algorithm.
	-----------------------------------------------------

2- Use substution method
	Copy smallest element of ar1 and ar2 into temp first.
	As, this is done in merge sort.
	
	T.C = O(n+m) - time to copy elements into temp.
	A.S = O(n+m) - space to store temp. 
	-----------------------------------

3- 
*/

/**
 * Take two sorted array as input and merge them as a single sorted array.
 * The merging should be inplace.
 * All initial elements should be in ar1 and all others should be in ar2.
 *
 * @param {ar1} - array one
 * @param {ar2} - array two
 * @param {n} - size of ar1
 * @param {m} - size of ar2
 */
void solve(int ar1[], int ar2[],int n, int m){
	
}
// driver code
int main(){
	// I/O
	IOS;

    #ifndef ONLINE_JUDGE
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);
    #endif
	cout<<"Started\n";
	int T;
	cin>>T;
	// reading input
	while(T--){
		cout<<"-----------------------------\n";
		int n,m; cin>>n>>m; int ar1[n],ar2[m]; for(int i=0;i<n; i++) cin>>ar1[i]; for(int i=0;i<m; i++) cin>>ar2[i];
		solve(ar1,ar2,n,m);
	}
	cout<<"\nDone:)\n";
	return 0;
}

