//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Print subset for given elements
// T.C         : O(2^n)
// A.S         : O(n)
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

/**
 * @param {int} n length of input
 * @param {array} ar input array
 * @param {int} idx current index to be processed
 * @param {array} subset current subset is being processed
 */
void printSubSet(int n, int ar[], int idx,vector<int>&subset){
	cout<<"SubSet: ";
	for(auto i:subset)
		cout<<i<<" ";
	cout<<endl;

	for(int i=idx; i<n; i++){
		subset.push_back(ar[i]);
		printSubSet(n,ar,i+1,subset);
		subset.pop_back();
	}
}
// driver code
int main(){
	// I/O
	IOS;

    #ifndef ONLINE_JUDGE 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);  
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
	int t;
	cin>>t;
	while(t--){
		int n; cin>>n;
		int ar[n];
		bool mark[n];
		memset(mark,0,sizeof mark);
		vector<int>subset;
		for(int i=0; i<n; i++)
			cin>>ar[i];
			
		// print
		printSubSet(n,ar,0,subset);
	}
	return 0;
}