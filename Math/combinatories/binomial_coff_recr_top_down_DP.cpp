//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Find binomial coefficent using dynamic programming. 
// T.C         : O(n*k)
// A.S         : O(n*k)
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// 2D array
#define twoD(row,col,name) int **name=new int*[row];for(int i=0;i<row;i++){name[i]=new int[col];}
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

/**
 * Find binomial coefficent of the given numbers using dynamic programming. 
 * @param n number 1
 * @param k number 2
 * @return binomian coefficent of n and k, ie. nCk
 */
int binomial(int n,int k,int **c){
	if(c[n][k]!=-1)
		return c[n][k];

    // if c(n,0)==c(n,n)==1
    if(k==0||k==n){
		c[n][k]=1;
		return 1;
	}

	c[n][k]=binomial(n-1,k-1,c)+binomial(n-1,k,c);
	return c[n][k];
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
   // cout<<binomial(n,k);
  	twoD(n+1,k+1,c);
	  for(int i=0;i<=n;i++){
		for(int j=0;j<=k;j++){
			c[i][j]=-1;
		}
	}
	binomial(n,k,c);
	
	//memset(c,-1,sizeof(c[0][0])*n*k);
	cout<<c[n][k];
	return 0;
}