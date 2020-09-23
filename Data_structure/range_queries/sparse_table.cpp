//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Range minimum query using sparse table in O(1) time.
// T.C         : O()
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

int const MAX = 1000;
int const logN = log2(MAX)+1;
int sparse[MAX][logN];

/**
 * Build function of sparse table.
 * This function takes an array and size of the array as input.
 * This function makes a sparse table out of the input.
 * 
 * @param {ar} - input array
 * @param {n} - size of the array
 */
void build(int ar[], int n){
	// for a single element, minimum will be the element itself
	for(int i=0; i<n; i++)
		sparse[i][0] = i;
	
	// this is the maximum range of the array in power of 2^logJ
	int logJ = ceil(log2(n));
	
	// store the information in interval of power of two
	for(int j=1; (1<<j)<n; j++){
		for(int i=0; (i+(1<<j))<=n; i++){
			if(ar[sparse[i][j-1]] < ar[sparse[i + (1 << (j - 1))][j-1]])
				sparse[i][j] = sparse[i][j-1];
			else sparse[i][j] = sparse[i + (1 << (j - 1))][j-1];
		}
	}
}

/**
 * Return the minimum element in given range. 
 * @param {l} - starting of the range
 * @param {r} - end of the range
 * @param {ar} - input array
 * @return {int} - minimum element of the range. 
 */
int query(int ar[],int l, int r){
	int n = r-l+1;
	int k = log2(n); // precompute it incase of large number of query...
	int ans = INT_MAX;
	// compute the largest interval first then smallest>> and so on.
	// size of each interval would be maximumm 2^j
	for(int j=k; j>=0; j--){
		if(l+(1<<j)-1 <= r){
			ans = min(ar[sparse[l][j]],ans);
			// l to 2^j has been already computed so shift l by 2^j..
			l += 1<<j;
		}
	}
	return ans;	
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
	// set all value of sparse[][] to -1
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			sparse[i][j] = -1;
			
	int ar[n];
	for(int i=0;i<n;i++) cin>>ar[i];
	build(ar,n);
	// print array
	for(int i=0;i<n;i++) cout<<ar[i]<<" "; cout<<"\n----------------------\n"<<endl;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			if(sparse[i][j] != -1)
				cout<<sparse[i][j]<<" ";
		cout<<endl;
	}
	
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<"\n----------------\n";
		cout<<query(ar,l,r)<<endl;
	}
	cout<<"\nDone:)\n";
	return 0;
}

