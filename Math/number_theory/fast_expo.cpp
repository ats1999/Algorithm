//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Find exponential of a number in very convenient way...
// T.C         : O(LogN)
// A.S         : O(1)
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

/**
 * This function finds exponential of the given numbers.
 * 
 * Time complexity of this function is O(N)
 * We are simply multiplying a n times like, A x A x ... x A
 * @param {a} 
 * @param {n}
 * @return {int} a^n
 */
int expo(int a,int n){
    int res = a;
    for(int i=0;i<n-1;i++){
        res *= a;
    }
        
    return res;
}

/**
 * This function finds exponential of the given numbers in an efficient way.
 * 
 * Time complexity of this function is O(logN)
 * We are simply multiplying a n times like, A x A x ... x A
 * @param {a} 
 * @param {n}
 * @return {int} a^n
 */
int fastExpo(int a,int n){
    // base case, math formula
    if(n==0)
        return 1;
    // base case, math formula
    if(n==1)
        return a;
    
    int R = fastExpo(a,n>>1);
    if(n%2==0)
        return R * R;
    else return R * a * R;
}
// driver code
int main(){
	cout<<"Started\n";
	// I/O
	IOS;

    // #ifndef ONLINE_JUDGE 
	//     freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);  
	//     freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    // #endif 
    int a,n;
     cin>>a>>n;
     cout<<expo(a,n);
	cout<<"\nDone:)\n";
	return 0;
}