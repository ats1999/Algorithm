//============================================================================
// Name        : ganesha.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Print ganesha pattern like below example. 
// Note 	   : N is always odd...
//============================================================================

/********************************************************************************************

:- When input is seven then pattern looks like. 
---------------------------------------------------------------------------------------------

	*  ****
	*  *
	*  *
	*******
	   *  *
	   *  *
	****  *
	
----------------------------------------------------------------------------------------------

:- When input is eleven(11) then pattern looks like
-----------------------------------------------------------------------------------------------

	*    ******          
	*    *
	*    *
	*    *
	*    *
	***********
	     *    *
	     *    *
	     *    *
	     *    *
	******    *
*/
#include<bits/stdc++.h>
using namespace std;

// driver code
int main(){
	int n=0;
	
	// get value from user
	printf("Enter (odd) value of n>=5: ");
	scanf("%d",&n);
	
	if(n%2==0||n<5){
		printf("Wrong input\n");
		exit(0);
	}
		
	printf("\n\n\n\n");
	
	// print top level component
	// print one *
	printf("*");
	
	// print n/2-1 space
	for(int i=0;i<(n/2)-1;i++)
		printf(" ");
	
	// print (n+1)/2 *
	for(int i=0;i<(n+1)/2;i++)
		printf("*");
	printf("\n");
	
	// for n/2-1 times print  * and n/2-1 space and *
	for(int i=0;i<n/2-1;i++){
		printf("*");
		// print space
		for(int i=0;i<n/2-1;i++)
			printf(" ");
		printf("*");
		printf("\n");
	}
	
	// print middle component
	// n time print *
	for(int i=0;i<n;i++)
		printf("*");
	printf("\n");
	
	// print bottom level component
	// for n/2-1 time print n/2 time space then * then n/2-1 space then *
	for(int i=0;i<n/2-1;i++){
		// print space
		for(int i=0;i<n/2;i++)
			printf(" ");
		
		// print *
		printf("*");
		
		// print n/2-1 times space
		for(int i=0;i<n/2-1;i++)
			printf(" ");
		
		// print *
		printf("*");
		printf("\n");
	}
	
	// print (n+1)/2 *
	for(int i=0;i<(n+1)/2;i++)
		printf("*");
	
	// print n/2-1 space 
	for(int i=0;i<n/2-1;i++)
		printf(" ");
		
	// print *
	printf("*");
	printf("\n\n\n\n");
	return 0;
}

