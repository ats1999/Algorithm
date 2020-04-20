//============================================================================
// Name        : ssc.cpp
// Author      : Rahul
// Version     : C++14
// Copyright   : Everyone can freely use and distribute it. 
// Description : This file is created with the aim in mind that, duering programming,
//			   : we will find usefull function or boilerplate code in just a second.
// Note        : use zero based indexing!
//============================================================================


#include<bits/stdc++.h>
using namespace std;
/**
 * This class represents Graph. 
 * It assume that you are implementing graph which have node starting from 1.
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
		* This function return transpose of any graph.
		*/
        Graph getTranspose(){
        	// create a new graph 
        	Graph g(v);
        	// for all vertices in old graph 
        	for(int ver=0;ver<v;ver++){
        		// for all adjacents node in old graph
        		for(auto it=adj[ver].begin();it!=adj[ver].end();it++){
        			g.adj[*it].push_back(ver);
				}
			}
			return g;
		}
        /**
		* This function recersively call dfsUtill.
		* @param src a node:
		* @param visited a bool[]:
		*/
		void dfsUtill(int src,bool visited[]){
			// visit
			cout<<src<<" ";
			visited[src]=true;
			// call dfsUtill for each adjacent node(unvisited)
			for(auto it=adj[src].begin();it!=adj[src].end();it++){
				if(!visited[*it])
					dfsUtill(*it,visited);
			}
		}
		/**
		* This function find all strongly connected components.
		*/
		void scc(){
			// create a stack
			stack<int>Stack;
			
			// mark all vertices as not visited
			bool visited[this->v];
			for(int i=0;i<this->v;i++)
				visited[i]=false;
				
			// fill all vertices in the stack according to their finish time.
			for(int i=0;i<this->v;i++)
				if(!visited[i])
					fillOrder(i,visited,Stack);
			
			// get transpose of the graph
			Graph gt=getTranspose();
			
			// mark all vertices as not visited for second DFS
			for(int i=0;i<v;i++)
				visited[i]=false;
		
			// now process all vertices in order defined by stack
			while(!Stack.empty()){
				// pop a vertex from stack
				int v=Stack.top();
				Stack.pop();
				
				// print scc of poped vertex
				if(!visited[v])
					gt.dfsUtill(v,visited);
						cout<<endl;
			}
		}
		/**
		* This function fill vertices into stack according to their finish time. 
		*/
		void fillOrder(int v, bool visited[],stack<int>&Stack){
			// mark the current node as visited
			visited[v]=true;
			
			// recurr for all verticies adjacent to this vertex
			for(auto it=adj[v].begin();it!=adj[v].end();it++){
				if(!visited[*it])
					fillOrder(*it,visited,Stack);		
			}
			// all vertices that are rechable from v are pushed by now. 
			Stack.push(v);
		}
		
		/**
         * This function print list represention of the graph.
         */
        void print(){
            // for every vertex
            for(int i=0;i<this->v;i++){
                // every connected edge from vertex
                cout<<i<<"-> ";
                for(int node:adj[i]){
                    cout<<node<<" ";
                }
                cout<<endl;
            }
        }
};
int main(){
	Graph g(10);
	g.addEdge(1,0);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,1);
	g.addEdge(4,5);
	g.addEdge(4,7);
	g.addEdge(4,6);
	g.addEdge(5,0);
	g.addEdge(6,8);
	g.addEdge(8,9);
	g.addEdge(9,6);
	g.print();
	g.scc();
	return 0;
}
