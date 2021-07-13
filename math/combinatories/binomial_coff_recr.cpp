//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Find binomial coefficent using rcursiv method. 
// T.C         : O()
// A.S         : O()
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

/**
 * Find binomial coefficent of the given numbers. 
 * @param n number 1
 * @param k number 2
 * @return binomian coefficent of n and k, ie. nCk
 */
int binomial(int n,int k){
    // if c(n,0)==c(n,n)==1
    if(k==0||n==k)
        return 1;
    return binomial(n-1,k-1)+binomial(n-1,k);
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
    int n,k;
    cin>>n>>k;
    cout<<binomial(n,k);
	return 0;
}