//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Find the number of equals the number of valid parenthesis expressions
//              -that consist of n left parentheses and n right parentheses.
// T.C         : O()
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
/**
 * This function return catalan number for the given number. 
 * 
 * It can also calculated using binomial coefficient.
 * See book=>
 * @param {int} c
 * @return {int} catalan number for c
 */
long long int catalanNumber(long long int c){
	// base case-> view in the book
	if(c<=1)
		return 1;

	long long int res = 0;
	for(int i = 0; i < c; i++){
		res += catalanNumber(i) * catalanNumber(c-i-1);
	}
	return res;
}
/**
 * This function returns the number of valid paranthesis expression that can 
 * be constructed using n left and n right paranthesis. 
 * 
 * If n = 3 then solution is...
 * ()()()
 * ((()))
 * (())()
 * ()(())
 * (()())
 * Total 5 expressions can be constructed. 
 * 
 * @param {int} n
 * @return {int} number of valid paranthesis expression.
 */
int numValidParenthesis(int n){
	return catalanNumber(n);
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
    int n;
	cin>>n;
	for(int i=0;i<10;i++)
	cout<<catalanNumber(i)<<endl;
	cout<<"\nDone:)\n";
	return 0;
}