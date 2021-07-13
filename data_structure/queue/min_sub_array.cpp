//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Finding minimum of all subarray of of length k of an array.
// 				 - use queue data structure.
// T.C         : O(N)
// A.S         : O(k) if we store, O(1) if online algorithm used...
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
// helper function
void print(vector<int>V){
	for(int n:V)
		cout<<n<<" ";
	cout<<endl;
}

/**
 * This function finds minimum of all subarray of length k.
 * @param {input} - input array
 * @param {output} - output array
 * @param {k} - subarray size
 */
void push(vector<int>&input, vector<int>&output, int k){
	if(input.size()<k){
		cout<<"Bad input\n";
		return;
	}
	
	queue<int>Q;
	int minElem = INT_MAX;
	// put first k elements into queue
	for(int i=0; i<k; i++){
		Q.push(input[i]);
		minElem = min(minElem,input[i]);
	}
	output.push(minElem);
	for(int i=k; i<n; i++){
		int top = Q.top();
		Q.pop();
		Q.push(input[i]);
		if(minElem != top)
			minElem = min(minElem,input[i]);
		else minElem = min(,input[i]);	
	}	
}
// driver code
int main(){
	// I/O
	IOS;

    #ifndef ONLINE_JUDGE
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);
    #endif
	cout<<"Started\n";
	int n;
	cin>>n;
	while(n--){
		int m;
		cin>>m;
		
	}
	cout<<"\nDone:)\n";
	return 0;
}

