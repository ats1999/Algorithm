//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Edit distance classical problem.
//                 Recursive implemention...
// T.C         : O(3^n)
// A.S         : O(1)
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

/**
 * This function count edit diistance between string x and y.
 * @param x a string
 * @param y another string
 * @param m size of x
 * @param n size of y
 * @return distance
 */
int editDistance(string x,int m,string y,int n){
    // base case if string is empty
    if(m==0)
        return n;
    if(n==0)
        return m;

	int cost=0;
    if(x[m-1]!=y[n-1])
		cost=1;
	
	return min(editDistance(x,m-1,y,n)+1,
	min(editDistance(x,m,y,n-1)+1,editDistance(x,m-1,y,n-1)+cost));
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
    string x,y;
	cin>>x>>y;
	int m,n;
	m=x.length(),n=y.length();
	cout<<editDistance(x,m,y,n);
	return 0;
}