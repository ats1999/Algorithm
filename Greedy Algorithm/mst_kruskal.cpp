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
// utility function to sort graph using non-decreasing order of their weight
bool comp(pair<pair<int,int>,int> p1,pair<pair<int,int>,int> p2){
	return p1.second<p2.second;
}

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
		* @param edge : E of any Graph.
		* @pram n: size of G
		* @return : Minimum MST cost. 
		*/
		int kruskalMST(vector<pair<pair<int,int>,int>>edge,int n){
			// to store minimum MST cost
			int sum=0;
			// sort edges according to their weight
			sort(edge.begin(),edge.end(),comp);
			cout<<"After sorting\n";
			for(auto it:edge){
				cout<<it.first.first<<"->"<<it.first.second<<" "<<it.second<<endl;
			}
			// create a disjoint set to detect cycle. 
			DisjSet set(n);
			// for every edge in set E check considering that edge makes a cycle or not.
			// if consedring that edge is making a cycle then do not include it
			// otherwise include it. 
			for(auto it:edge){
				n--;
				if(set.isUnion(it.first.first,it.first.second)){
					sum=sum+it.second; // add weight of current edge to sum. 
					// if n-1 edge included in MST then no further edge can be inserted 
					cout<<it.second<<endl;
				//	if(!n)
				//		break;
				}
			}
			return sum; 
		}
};

int main(){
	// store edge connectivity information
	// pair is consist of a pair of connected edge and their weight
	vector<pair<pair<int,int>,int>>edge;
	
	// to avoid doubling vector each time
	int n=100; // number of edge
	edge.reserve(n);
	// push edge information
	// edges are bidirectional
	edge.push_back(make_pair(make_pair(1,2),1));
	edge.push_back(make_pair(make_pair(2,3),2));
	edge.push_back(make_pair(make_pair(4,5),3));
	edge.push_back(make_pair(make_pair(6,7),3));
	edge.push_back(make_pair(make_pair(1,4),4));
	edge.push_back(make_pair(make_pair(2,5),4));
	edge.push_back(make_pair(make_pair(4,7),4));
	edge.push_back(make_pair(make_pair(3,5),5));
	edge.push_back(make_pair(make_pair(2,4),6));
	edge.push_back(make_pair(make_pair(3,6),6));
	edge.push_back(make_pair(make_pair(5,7),7));
	edge.push_back(make_pair(make_pair(5,6),8));
		
	// call the function
	// 7 is number of vetices
	Graph g(0);
	cout<<"\n"<<g.kruskalMST(edge,7);
	return 0;
}
