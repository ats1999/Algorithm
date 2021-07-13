//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Inversion count using D & C (merge sort)
// T.C         : O(nlogn)
// A.S         : O(n)
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

int merge(int ar[],int ar1[], int ar2[], int n, int m){
	int i=0,j=0,k=0,count=0;
	while(i<n && j<m){
		if(ar1[i]>ar2[j]){
			ar[k] = ar2[j];
			count+=n-i;
			j++;
		}else{
			ar[k] = ar1[i];
			i++;
		}
		k++;
	}

	for(int idx = i; idx<n; idx++){
		ar[k] = ar1[idx];
		k++;
	}
	for(int idx = j; idx<m; idx++){
		ar[k] = ar2[idx];
		k++;
	}

	return count;
}
int mergeSort(int ar[], int n,int count){
	if(n==1)
		return 0;
	int mid = n/2;
	int ar1[mid],ar2[n-mid];

	// copy in first array
	for(int i=0; i<mid; i++)
		ar1[i] = ar[i];
	
	// copy second array
	for(int i=mid; i<n; i++)
		ar2[i-mid] = ar[i];

	int c1 = mergeSort(ar1,mid,count);
	int c2 = mergeSort(ar2,n-mid,count);
	int c3 = merge(ar,ar1,ar2,mid,n-mid);
	return c1+c2+c3;
}
// driver code
int main(){
	// I/O
	IOS;

    #ifndef ONLINE_JUDGE 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);  
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
    int n;
    cin>>n;
    int ar[n];
    for(int i=0; i<n; i++)
        cin>>ar[i];
	cout<<"count: "<<mergeSort(ar,n,0)<<endl;
	return 0;
}