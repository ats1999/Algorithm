//============================================================================
// Name        : tree.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Represention of tree data structure.
//============================================================================
#include<bits/stdc++.h>
using namespace std;
#include "tree.h"
#include "insert.h"
#include "in_order.h"
#include "pre_order.h"
#include "post_order.h"
// driver code
int main(){
	Tree *root=NULL;
	
	root=insert(root,45);
	insert(root,50);
	insert(root,15);
	insert(root,20);
	insert(root,47);
	in_order(root);
	cout<<endl;
	pre_order(root);
	cout<<endl;
	post_order(root);
	return 0;
}

