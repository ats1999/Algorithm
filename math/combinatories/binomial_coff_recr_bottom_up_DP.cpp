//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Find binomial coefficent in bottom up manner using dynamic programming. 
// T.C         : O(n*k)
// A.S         : O(n*k)
//============================================================================
#include<bits/stdc++.h>
using namespace std;
#define twoD(row,col,name) int **name=new int*[row];for(int i=0;i<row;i++){name[i]=new int[col];}
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
/**
 * Find binomial coefficent of the given numbers using dynamic programming. 
 * @param n number 1
 * @param k number 2
 * @return binomian coefficent of n and k, ie. nCk
 */
int binomial(int n,int k,int **c){
	for(int i=0;i<=n;i++){
        for(int j=0;j<=min(i,k);j++){
            if(j==0||j==i)
                c[i][j]=1;
            else c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
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
	
	//memset(c,-1,sizeof(c[0][0])*n*k);
	cout<<binomial(n,k,c);
		return 0;
	}