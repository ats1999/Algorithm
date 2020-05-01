//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description :
//============================================================================
#include<bits/stdc++.h>
#include "disj_set.h"
using namespace std;

// driver code
int main(){
	DisjSet set(7);
	
	if(set.areInSameSet(1,2))
	cout<<"Discarded "<<1<<" "<<2<<endl;
	else cout<<" "<<1<<" "<<2<<endl;
	set.isUnion(1,2);
	set.printSet();
	
	if(set.areInSameSet(2,3))
	cout<<"Discarded "<<2<<" "<<3<<endl;
	else 	cout<<" "<<2<<" "<<3<<endl;
	set.isUnion(2,3);
	set.printSet();
	
	if(set.areInSameSet(4,5))
	cout<<"Discarded "<<4<<" "<<5<<endl;
	else cout<<" "<<4<<" "<<5<<endl;
	set.isUnion(4,5);
	set.printSet();
	
	if(set.areInSameSet(6,7))
	cout<<"Discarded "<<6<<" "<<7<<endl;
	else cout<<" "<<6<<" "<<7<<endl;
	set.isUnion(6,7);
	set.printSet();
	
	if(set.areInSameSet(1,4))
	cout<<"Discarded "<<1<<" "<<4<<endl;
	else cout<<" "<<1<<" "<<4<<endl;
	set.isUnion(1,4);
	set.printSet();
	
	if(set.areInSameSet(2,5))
	cout<<"Discarded "<<2<<" "<<5<<endl;
	else cout<<" "<<2<<" "<<5<<endl;
	set.isUnion(2,5);
	set.printSet();
	
	if(set.areInSameSet(4,7))
	cout<<"Discarded "<<4<<" "<<7<<endl;
	else cout<<" "<<4<<" "<<7<<endl;
	set.isUnion(4,7);
	set.printSet();
	
	if(set.areInSameSet(3,5))
	cout<<"Discarded "<<3<<" "<<5<<endl;
	else cout<<" "<<3<<" "<<5<<endl;
	set.isUnion(3,5);
	set.printSet();
	
	if(set.areInSameSet(2,4))
	cout<<"Discarded "<<2<<" "<<4<<endl;
	else cout<<" "<<2<<" "<<4<<endl;
	set.isUnion(2,4);
	set.printSet();
	
	if(set.areInSameSet(3,6))
	cout<<"Discarded "<<3<<" "<<6<<endl;
	else cout<<" "<<3<<" "<<6<<endl;
	set.isUnion(3,6);
	set.printSet();
	
	if(set.areInSameSet(5,7))
	cout<<"Discarded "<<5<<" "<<7<<endl;
	else cout<<" "<<5<<" "<<7<<endl;
	set.isUnion(5,7);
	set.printSet();
	
	if(set.areInSameSet(5,6))
	cout<<"Discarded "<<5<<" "<<6<<endl;
	else cout<<" "<<5<<" "<<6<<endl;
	set.isUnion(5,6);
	set.printSet();
	
	set.printSet();
	set.printSize();
	return 0;
}

