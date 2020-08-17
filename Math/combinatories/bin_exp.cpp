//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : https://cp-algorithms.com/algebra/binary-exp.html
// T.C         : O(logN) - using DP
// A.S         : O(logN) - using DP
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

/**
 * This function finds binary expontiation and returns a^n.
 * @param {int} a
 * @param {int} n
 * @return {int} a^n
 */
int binExp(long long int a, long long int n){
	long long int res=1;
	while(n>0){
		if(n&1)
		 res = res*a;

		a = a*a;
		n>>=1;
	}
	return res;
}
// driver code
int main(){
	cout<<"Started\n";
	// I/O
	IOS;

    #ifndef ONLINE_JUDGE 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);  
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
    
	cout<<"\nDone:)\n";
	return 0;
}