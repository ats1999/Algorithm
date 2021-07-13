//============================================================================
// Name        : weighted_graph.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it. 
// Description : Repersention of weighted graph.
// Note 	   : 0 based indexing used in this graph
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#include "weighted_graph.h"

int main(){
	Graph g(6);
	g.addEdge(1,5,8);
	g.addEdge(1,2,4);
	g.addEdge(4,2,78);
	g.addEdge(3,4,78);
	g.print();
	return 0;
}
