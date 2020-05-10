//============================================================================
// Name        : make_change.cpp
// Author      : Rahul
// Version     : 2.0
// Copyright   : Everyone freely can use and distribute it.
// Description : Program to make change of any amount with minimum number of coins.
// Note		   : This works for only Indian Denominations.
//			   : input array should be sorted.
// T.C		   : O(n)
//============================================================================
#include<bits/stdc++.h>
using namespace std;

/**
* This function find the minimum number of coins needed to make change of the given number.
* @param coin[]: a sorted array in decending order - Contains coins with their value
* @param numDeno: Number of denominations 
* @param num : an int - number required to make change.
* @return count: minimum number of coins
*/

int makeChange(int coin[],int numDeno,int num){
	int count=0,sum=0;
	// for each coin available
	for(int i=0;i<numDeno;i++){
		// if sum is less than or equals to given number
		while(sum+coin[i]<=num){
			// include current coin into solution
			sum+=coin[i];
			count++;
		}//else i++;
	}
	return count;
}
 // driver code
 int main(){
 	int coin[5]={50,20,10,5,1}; // denominations
 	cout<<"91 Cents: "<<makeChange(coin,5,91)<<" coins needed\n";
 	cout<<"50 Cents: "<<makeChange(coin,5,50)<<" coins needed\n";
 	cout<<"37 Cents: "<<makeChange(coin,5,37)<<" coins needed\n";
 }
