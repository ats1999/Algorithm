//============================================================================
// Name        : knapsack_dp_recusive.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Solve knapsack problem using memorization.
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
int knapsackUtil(int wt[],int val[],int n,int w,int **dp){
	if(n==0||w==0)
		return 0;
	if(dp[n][w]!=-1)
		return dp[n][w];
	// if the weight of the current item is more than w then this item can not be included.
	if(wt[n-1]>w)
		return knapsackUtil(wt,val,n-1,w,dp);
	else 
	{
		// check that current item can be included in optimal solution or not
		dp[n][w]=max(val[n-1]+knapsackUtil(wt,val,n-1,w-wt[n-1],dp),knapsackUtil(wt,val,n-1,w,dp));
		return dp[n][w];
	}
}
/**
* This is utility function. 
* It creates DP array to help this program.
* @param weight[]: input weight array
* @param profir[]: input profit array
* @param n: number of objects/items.
* @param w: capicity of the knapsack. 
* @return maximum profit. 
*/
int knapsack(int wt[],int val[],int n,int w){
	int** dp; // double pointer to declare the table dynamically 
    dp = new int*[n]; 
  
    // loop to create the table dynamically 
    for (int i = 0; i < n; i++)  
        dp[i] = new int[w + 1];     
  
    // loop to initially filled the table with -1 
    for (int i = 0; i < n; i++)  
        for (int j = 0; j < w + 1; j++)  
            dp[i][j] = -1; 
    return knapsackUtil(wt,val,n-1,w,dp);
}
// driver code
int main(){
	
	// objects with their weight and profit respectively
	int profit[]={1,6,18,22,28};
	int weight[]={1,2,5,6,7};
	 cout<<knapsack(weight,profit,6,11);
	return 0;
}

