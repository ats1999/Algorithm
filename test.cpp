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

void printSubSet(int n, int ar[], bool mark[],vector<int>&subset){
	if(subset.size() == n){
		// print subset and return
		return;
	}

	for(int i=0; i<n; i++){
		if(mark[i])
			continue;
		subset.push_back(ar[i]);
		mark[i] = true;
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
		printSubSet(n,ar,mark,subset);
	}
	return 0;
}