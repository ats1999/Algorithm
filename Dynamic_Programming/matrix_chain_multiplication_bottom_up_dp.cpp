//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description :
// T.C         : O(n^3)
// A.S         : O(n)
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

/**
 * This function finds best order of matrices to be multiplied.
 * @param {m} array containing row and colums of matrices
 * @param {i} start index
 * @param {i} end index
 * @return order of matrix || cost of multiplication 
 */
int matrixChain(int m[],int n){
    int dp[5][5];
   for(int i=0;i<n;i++)
      dp[i][i]=0;

    for(int l=2;l<n;l++){
        for(int i=1;i<n-1;i++){
            int j=i+l-1;
            dp[i][j]=INT_MAX;

            for(int k=i;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+m[i-1]*m[k]*m[j]);
            }
        }
    }
    return dp[1][n-1];
}
// driver code
int main(){
	cout<<"Started\n";
	// I/O
	//IOS;
    
    #ifndef ONLINE_JUDGE 
	    // For getting input from input.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin); 
	    // Printing the Output to output.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
    int m[]={1,2,3,4};
    cout<<matrixChain(m,4)<<endl;
	return 0;
}