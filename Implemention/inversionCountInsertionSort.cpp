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
int inversionCount(int A[], int size){
    int mod = 100000007;
    int count = 0;
    for(int i=1; i<size; i++){
        int j = i-1;
        while(j>=0 && A[j]>A[j+1]){
            swap(A[j],A[j+1]);
            j--;
            count++;
            if(count>=mod)
                count%=mod;
        }
    }
    return count;
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
	cout<<"count: "<<inversionCount(ar,n)<<endl;
	return 0;
}