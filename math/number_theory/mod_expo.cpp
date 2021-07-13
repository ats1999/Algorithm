//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Find modular exponintation. 
// T.C         : O(LogN) 
// A.S         : O(logN) and O(n)-using bitmasking
//
// http://homepages.math.uic.edu/~leon/cs-mcs401-s08/handouts/fastexp.pdf
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

/**
 * This function finds modular expontiation of the given numbers. 
 * @param {a} 
 * @param {n}
 * @param {m}
 * @return {int} a^m%m
 */
long long int modFastExpo(long long int a,long long int n,long long int m){
    if(n==0)
        return 1 % m;
    if(n==1)
        return a % m;

    int res = modFastExpo(a,n>>2,m);
    
    // when n is even
    res = (res * res) % m;

    // when n is odd
    if(n%2!=0)
        res = (res * a) % m;
    
    return res;
}

/**
 * This function finds modular expontiation of the given numbers. 
 * This complexity of this function is O(n).
 * @param {a} 
 * @param {n}
 * @param {m}
 * @return {int} a^m%m
 */
long long int modPow(long long int a,long long int n,long long int m){
    long long int res = a;
    for(int i=0;i<n-1;i++){
        res *= a%m ;
    }
    return res % m;
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