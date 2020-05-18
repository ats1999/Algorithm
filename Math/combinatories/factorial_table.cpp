//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Find factorial from 1 to the given range. 
// T.C         : O(n)
// A.S         : O(n) to store table
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
/**
 * Find factorial of the given number. 
 * @param n input number whose table needs to be preapared. 
 */
void factorialTable(int n,int ar[]){
    // factorial of zero is 1
    ar[0]=1;

    for(int i=1;i<=n;i++)
        ar[i]=i*ar[i-1];
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
    int ar[10];
    factorialTable(10,ar);
    for(int i=0;i<10;i++)
        cout<<ar[i]<<" ";
	return 0;
}