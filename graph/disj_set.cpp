//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description :
//============================================================================
#include<bits/stdc++.h>

using namespace std;
#include "disj_set.h"
// driver code
int main(){
	DisjSet set(7);
	set.isUnion(1,2)
	
	set.isUnion(2,3);
	
	set.isUnion(4,5);
	
	set.isUnion(6,7);
	set.printSet();
	
	set.isUnion(1,4);
	
	set.isUnion(2,5);
	
	set.isUnion(4,7);
	
	set.isUnion(3,5);
	
	set.isUnion(2,4);
	
	set.isUnion(3,6);
	
	set.isUnion(5,7);
	
	set.isUnion(5,6);
	
	set.printSet();
	set.printSize();
	return 0;
}

