//============================================================================
// Name        : gcd.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Find GCD of two given numbers. 
//============================================================================
#include<bits/stdc++.h>
using namespace std;
/**
* This function is used to finf  GCD of two number.
* @param a: an integer - first number
* @param b: an integer - second number
* @return : an integer - GCD of a and b
*/
int gcd(int a,int b){
	if(b==0)
		return a;
	cout<<"a: "<<a<<" b: "<<b<<endl;
	return gcd(b,a%b);
}
// driver code
int main(){
	cout<<"Started!...\n";
	int a,b;
	cin>>a>>b;
	cout<<"GCD: "<<gcd(a,b);
	cout<<"\n End---...\n";
	return 0;
}

