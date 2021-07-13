//============================================================================
// Name        : floyd.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Implements Floyd algorithm to get all point sortest path. 
// 			   - This algoithms find sortest path between all points of the graph.  
// T.C		   : O(n^3)
// A.S		   : O(1)
//============================================================================
#include<bits/stdc++.h>
using namespace std;
/**
* This function find sortest path between all the points.
* @param n: number of nodes. 
* @param d: input graph
*/
void floyd(int n,int **d){
	// take each node as intermidate node one by one
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			// from node i to node j  ---------  i->j
			// store minimum of direct i->j and i->k->j  in d[i][j] 
			for(int j=0;j<n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}
// driver code
int main(){
	// this variable repersents infinity
	int mx=INT_MAX;  // sum of  all nodes, because INT_MAX will overflow.
	int graph[4][4]={
	{0,5,500,500}, // at the place of 500 put mx beacause there is no edge 
	{50,0,15,5},
	{30,500,0,15},
	{15,500,5,0}
	};
	// create a dynamic array
	int **d=new int*[4];
	for(int i=0;i<4;i++)
		d[i]=new int[4];
		
	// store values
	for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				d[i][j]=graph[i][j];
			}
		}
	
	floyd(4,d);
		// print ans
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			printf("%d ",d[i][j]);
		}
		printf("\n");
	}
	return 0;
}

