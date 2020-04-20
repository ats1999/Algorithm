//============================================================================
// Name        : Graph.cpp
// Author      : Rahul
// Version     : C++14
// Copyright   : Everyone can freely use and distribute it. 
// Description : This file is created with the aim in mind that, duering programming,
//			   : we will find usefull function or boilerplate code in just a second.
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
                cout<<i<<"-> ";
                for(int node:adj[i]){
                    cout<<node<<" ";
                }
                cout<<endl;
            }
        }
        /**
		* This function return transpose of any graph.
		*/
        Graph getTranspose(){
        	// create a new graph 
        	Graph g(this->v);
        	// for all vertices in old graph 
        	for(int v=1;v<this->v;v++){
        		// for all adjacents node in old graph
        		for(auto it=adj[v].begin();it!=adj[v].end();it++){
        			g.adj[*it].push_back(v);
				}
			}
			return g;
		}
};
int main(){
	Graph g(5+1);
	g.addEdge(1,5);
	g.addEdge(1,2);
	g.addEdge(4,2);
	g.addEdge(3,4);
	cout<<"Original graph:........\n";
	g.print();
	Graph nG=g.getTranspose();
	cout<<"Transposed graph:........\n";
	nG.print();
	return 0;
}
