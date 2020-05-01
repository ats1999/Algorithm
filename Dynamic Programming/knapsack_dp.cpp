//============================================================================
// Name        : knapsack_dp.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Solve knapsack using dynamic programming. 
//============================================================================
#include<bits/stdc++.h>
using namespace std;
/**
* This function find implements knapsack algorithm.
* @param weight[]: input weight array
* @param profir[]: input profit array
* @param n: number of objects/items.
* @param w: capicity of the knapsack. 
* @return maximum profit. 
*/
int knapsack(int wt[],int val[],int n,int w,int **dp){
	
	// set first row and first column to zero
	for(int i=0;i<=w;i++)
		dp[0][i]=0;
	for(int i=0;i<=n;i++)
		dp[i][0]=0;
	
	for(int i=1;i<n+1;i++){
		for(int j=0;j<w+1;j++){
			if(j<wt[i])
				dp[i][j]=dp[i-1][j];
			else{
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i]]+val[i]);
			}
		}
	}
	return dp[n][w];
}


/**
* This is a utility function.  
*/
int knapsackUtil(int wt[],int val[],int n,int w){
	int **dp=new int*[n+1];
	for(int i=0;i<=n;i++)
		dp[i]=new int[w+1];	
	
	knapsack(wt,val,6,11,dp);
}
// driver code
int main(){
	// objects with their weight and profit respectively
	int profit[]={1,6,18,22,28};
	int weight[]={1,2,5,6,7};
	 cout<<knapsackUtil(weight,profit,6,11);
	return 0;
}

