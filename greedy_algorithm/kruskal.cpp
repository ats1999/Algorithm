//============================================================================
// Name        : mst_kruskal.cpp
// Author      : Rahul
// Version     : 2.0
// Copyright   : Everyone freely can use and distribute it.
// Description : Find MST of given weighted and connected graph\
// Note		   : 0 based indexing used in this graph.
// 			   - Edges are bi-directional
// T.C		   : 
//============================================================================
#include<bits/stdc++.h>
using namespace std;
#include "../Graph/disj_set.h"

class Edge{
	public:
	int startNode;
	int endNode;
	int weight;
	// constructor to create edge
	Edge(int s, int e, int w){
		startNode = s;
		endNode = e;  
		weight = w;
	}
};

int main(){
	
	#ifndef ONLINE_JUDGE 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);  
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
	
	cout<<"Start\n";
	int numberOfEdge;
	cin>>numberOfEdge;
	vector<Edge>edgeList;

	int start, end, weight;
	while( numberOfEdge-- ){
		cin>> start >> end >> weight ;
		Edge e ( start, end, weight );
		edgeList.push_back(e);
	}

	//sort edge list according to their weight in non-increasing order
	sort(edgeList.begin(), edgeList.end(), [](Edge e1, Edge e2){
		return e1.weight < e2.weight;
	});

	DisjSet set(edgeList.size());

	int mst=0;
	for(auto edge:edgeList){
		if( !set.areInSameSet( edge.startNode, edge.endNode)){
			set.unite(edge.startNode, edge.endNode);
			mst += edge.weight;
		}
	}
	// cout<<mst;
	cout<<"\nEnd\n";
}
