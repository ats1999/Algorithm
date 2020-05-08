//============================================================================
// Name        : max_sub_qrray_sum.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : The algorithm is sometimes called Kadane’s algorithm.
// T.C         : sum - O(n)
//			   - sum1- O(n^2)
//		       - sum2- O(n^3)
//
// A.S         : O(1)
//============================================================================
#include<bits/stdc++.h>
using namespace std;
/**
* This function calculates maximum subarray sum 
* @param ar: input array
* @param n: size of array
* @return : maximum subarray sum
*/
int sum(int ar[],int n){
	int best=0,sum=0;
	for(int k=0;k<n;k++){
		sum=max(ar[k],sum+ar[k]);
		best=max(sum,best);
	}
	return best;
}
/**
* This function calculates maximum subarray sum 
* @param ar: input array
* @param n: size of array
* @return : maximum subarray sum
*/
int sum1(int ar[],int n){
	int best=0;
	for(int a=0;a<n;a++){
		int sum=0;
		for(int b=a;b<n;b++){
			sum+=ar[b];
			best=max(best,sum);
		}
	}
	return best;
}

/**
* This function calculates maximum subarray sum 
* @param ar: input array
* @param n: size of array
* @return : maximum subarray sum
*/
int sum2(int ar[],int n){
	int best=0;
	for(int a=0;a<n;a++){
		for(int b=a;b<n;b++){
			for(int k=a;k<b;k++){
				sum+=ar[k];
			}
			best=max(best,sum);
		}
	}	
	return best;
}
// driver code
int main(){
	int ar[]={-1,2,4,-3,5,2,-5,2};
    cout<<sum(ar,8);
	return 0;
}

