//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : This methods uses previously computed value.
// T.C         : O()
// A.S         : O()
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
/**
 * Find binomial coefficent of the given numbers using dynamic programming. 
 * @param n number 1
 * @param k number 2
 * @return binomian coefficent of n and k, ie. nCk
 */
int binomial(int n,int k){
    int c[k+1];
    memset(c,0,sizeof c);
    c[0]=1;
	for(int i=1;i<=n;i++){
        for(int j=min(i,k);j>0;j--){
            c[j]=c[j]+c[j-1];
            c[j]=c[j]%1000000000;
        }
    }
    for(int i:c)
        cout<<i<<" ";
        cout<<endl;
    return c[k];
}
// driver code
int main(){
	cout<<"Started\n";
	// I/O
	IOS;
    #ifndef ONLINE_JUDGE 
	    // For getting input from input.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin); 
	    // Printing the Output to output.txt file B
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
    int n,k;
    cin>>n>>k;
    cout<<binomial(n,k);
	return 0;
}