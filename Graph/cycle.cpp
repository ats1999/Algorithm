//============================================================================
// Name        : cycle.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : To detect cycle in the graph. 
// Note		   : 0 based indexin used in this graph. 
//============================================================================
#include<bits/stdc++.h>
using namespace std;
#include "weighted_graph.h"
// driver code
int main(){
	Graph g(5);
	g.addEdge(0,2,5);
	g.addEdge(1,3,45);
	g.addEdge(4,3,69); 
	g.print();
	return 0;
}

