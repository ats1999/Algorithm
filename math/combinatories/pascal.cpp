//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Program to generate pascal trangle.
// T.C         : O(n^3) time taken O(n)- for each row we have to generate a column O(n), each column element is a binomial coefficent O(n)
// A.S         : O(1)
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
/**
 * Function to find binomial coefficent.
 * @parma n
 * @param k
 * @return binomial coeefficent.
 */
int binomialCoeff(int n, int k) 
{ 
    int res = 1; 
    if (k > n - k) 
    k = n - k; 
    for (int i = 0; i < k; ++i) 
    { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
      
    return res; 
} 
/**
 * Function to generate pascal traingle. 
 * every row i has i elements in pascal traingle. 
 * every element of any row is binomial coefficnt of row number 0 to row
 */
void pascal(int n){
	for(int line = 0; line < n; line++){
		for(int elemOfLine = 0; elemOfLine <= line; elemOfLine++){
			cout<<binomialCoeff(line , elemOfLine)<<" ";
		}
		cout<<endl;
	}
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
	int n;
	cin>>n;
    pascal(n);
	return 0;
}