//============================================================================
// Name        : test.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : This file is only for testing........test... anything you want. 
//============================================================================
#include <bits/stdc++.h> 
using namespace std; 
#include "Graph/disj_set.h"

int main() 
{ 
	DisjSet d(5);
	int num1,num2;
	while(1){
		cout<<"Enter\n";
		cin>>num1>>num2;
		if(d.merge(num1,num2)){
			
		}else
		cout<<"\n cycle detected\n";
		d.print();
		d.printSize();
	}
	
} 

