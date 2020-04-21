//============================================================================
// Name        : finonacci.cpp
// Author      : Rahul
// Version     : 2.0
// Copyright   : Everyone freely can use and distribute it.
// Description : WAP to print fibonacci series.
//============================================================================

#include<bits/stdc++.h>
using namespace std;
// this function print nth fibonacci number
int fib(int n){
	if(n<2)
		return n;
	return fib(n-1)+fib(n-2);
}
// driver code
int main(){
	cout<<fib(9);
	return 0;
}

