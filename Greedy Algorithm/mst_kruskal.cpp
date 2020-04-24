//============================================================================
// Name        : mst_kruskal.cpp
// Author      : Rahul
// Version     : 2.0
// Copyright   : Everyone freely can use and distribute it.
// Description : Find MST of given weighted and connected graph\
// Note		   : 0 based indexing used in this graph.
// T.C		   : 
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
	vector<pair<int,int>>*adj;
	public:
		/**
         * Constructor to initialize the graph.
         * @param v an integer: number of nodes in the graph
         */
		Graph(int V){
			this->v=V;
			this->adj=new vector<pair<int,int>>[V];
		}
		
		/**
         * This function add a new edge to the graph.
         * @param u an integer: representing a node in the graph.
         * @param v an integer: representing a node in the graph.
         * @param w an integer: representing weight of any edge in the graph.
         * @param biDir a bool: true denotes bidirectional edge, unidirectional otherwise.
         */
		void addEdge(int u,int v,int w,bool biDir=true){
            adj[u].push_back(make_pair(v,w));
            if(biDir)
                adj[v].push_back(make_pair(u,w));
        }
        /**
         * This function print list represention of the graph.
         */
        void print(){
            // for every vertex
            for(int i=0;i<this->v;i++){
                // every connected edge from vertex
                for(auto edge:adj[i]){
                    cout<<i<<"->"<<edge.first<<"("<<edge.second<<")\t";
                }
                cout<<endl;
            }
        }
        /**
		* Function to find MST
		* @param g a Graph.
		*/
		void kruskalMST(Graph g){
			sort(g.adj);
			g.print();
		}
};

int main(){
	Graph g(6);
	g.addEdge(1,5,8);
	g.addEdge(1,2,4);
	g.addEdge(4,2,78);
	g.addEdge(3,4,78);
	kruskalMST(g);
	g.print();
	return 0;
}