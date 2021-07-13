//============================================================================
// Name        : Graph.cpp
// Author      : Rahul
// Version     : C++14
// Copyright   : Everyone can freely use and distribute it. 
// Description : This file is created with the aim in mind that, duering programming,
//			   : we will find usefull function or boilerplate code in just a second.
// Note:        1 based indexing has been used in this graph. 
//============================================================================


#include<bits/stdc++.h>
using namespace std;
/**
 * This class represents Graph. 
 * It assume that you are implementing graph which have node starting from 1.
 * It HAS:
 *         ONE: Constructor
 *            - Graph(int v);
 *         METHOD:
 *                 -1: addEdge(int u,int v,bool biDir);
 *                 -2: print();
 */
class Graph{
	int v; // number of vertices
	vector<int>*adj;
	public:
		/**
         * Constructor to initialize the graph.
         * @param v an integer: number of nodes in the graph
         */
		Graph(int V){
			this->v=V;
			this->adj=new vector<int>[V];
		}
		
		/**
         * This function add a new edge to the graph.
         * @param u an integer: representing a node in the graph.
         * @param v an integer: representing a node in the graph.
         * @param biDir a bool: true denotes bidirectional edge, unidirectional otherwise.
         */
		void addEdge(int u,int v,bool biDir=false){
            adj[u].push_back(v);
            if(biDir)
                adj[v].push_back(u);
        }
        /**
         * This function print list represention of the graph.
         */
        void print(){
            // for every vertex
            for(int i=1;i<this->v;i++){
                // every connected edge from vertex
                for(int node:adj[i]){
                    cout<<i<<"->"<<node<<"\t";
                }
                cout<<endl;
            }
        }
};
int main(){
	Graph g(5+1);
	g.addEdge(1,5);
	g.addEdge(1,2);
	g.addEdge(4,2);
	g.addEdge(3,4);
	g.print();
	return 0;
}
