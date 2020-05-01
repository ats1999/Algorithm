//============================================================================
// Name        : tralling_zero.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Find tralling zero from factorial of a given number. 
//============================================================================
#include<bits/stdc++.h>
using namespace std;
/**
* Function to find tralling zero. 
* @param n : input number - whose tralling zero is to be find. 
*/
int trallingZero(long long int n){
	int ans=0;
	int p=5;
	while((n/p)>0){
		ans+=n/p;
		p=p*5;
	}	
	return ans;
}
// driver code
int main(){
	cout<<trallingZero(100);
	return 0;
}

