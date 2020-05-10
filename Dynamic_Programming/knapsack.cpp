//============================================================================
// Name        : knapsack.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Implement standered knapsack problem. 
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
int knapsack(int wt[],int val[],int n,int w){
	if(n==0||w==0)
		return 0;
		
	// if the weight of the current item is more than w then this item can not be included.
	if(wt[n-1]>w)
		return knapsack(wt,val,n-1,w);
	else 
	// check that current item can be included in optimal solution or not
		return max(val[n-1]+knapsack(wt,val,n-1,w-wt[n-1]),knapsack(wt,val,n-1,w));
}
// driver code
int main(){ 
	// objects with their weight and profit respectively
	int profit[]={1,6,18,22,28};
	int weight[]={1,2,5,6,7};
	 cout<<knapsack(weight,profit,6,11);
	return 0;
}

