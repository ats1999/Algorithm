//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : In static array queries, the value array elements never changes.
// T.C         : O()
// A.S         : O()
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
// we have given an array and we need to answer report the sum of elements in the given range. 
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
	// given arrat
    int ar[8]={1,3,4,8,6,1,4,2};
	int prefix[8];// prifix array
	prefix[0]=ar[0];
	// each prefix array element contain sum in the range up to that point. 
	// now we can perform queries in O(1) time. 
	for(int i=1;i<8;i++){
		prefix[i]=prefix[i-1]+ar[i];
	}

	int i,k;
		cin>>i>>k;
		cout<<"Sum is range is: "<<prefix[k-1]-prefix[i-1]<<endl;
	return 0;
}