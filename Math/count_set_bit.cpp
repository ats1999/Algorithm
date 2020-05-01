//============================================================================
// Name        : count_set_bit.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Count set bits of any given number.
// Eg.		   : Binary repersention of 13 is 1101 so the number of set bits is 3
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//===============================================================================================
// First method
//===============================================================================================
/**
* Function to count set bits of a given number. 
* @param num : an int - input number
* T.C		 : O(n)
*/
int setBit(int num){
	int count=0;
	// check last bit, if it is one count it otherwise shift bits by 1
	while(num>0){
		count+=(num&1);
		num=num>>1;
	}
	return count;
}


//===============================================================================================
// Second method
//===============================================================================================

/**
* Count set bits of any given number. 
* T.C O(log(n)) - loop runs the number of time set bit persent.  eg. for 10000000 loop runs one time. 
*/
int countBit(int n){
	int count=0;
	while(n>0){
		n=n&(n-1);
		count++;
	}
	return count;
}
// driver code
int main(){
	cout<<countBit(13)<<endl;
	
	// inbuilt method	
	cout<<__builtin_popcount(13);
	return 0;
}

