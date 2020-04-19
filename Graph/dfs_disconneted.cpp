//============================================================================
// Name        : dfs_disconneted.cpp
// Author      : Rahul
// Version     : 2.0
// Copyright   : Everyone freely can use and distribute it.
// Description : DFS traversal of disconneted graph
//============================================================================

#include<bits/stdc++.h>
using namespace std;

class Graph{
	int v; // number of vertices
	vector<int>*adj;
	public:
		/**
         * Constructor to initialize the graph.
         * @param v an integer: number of nodes in the graph
         */
		Graph(int V){
			this->v=V+1;
			this->adj=new vector<int>[this->v];
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
		* This function is for DFS traversal for graph.
		* @param src a node: starting point of traversing.
		*/
		void dfs(int src){
			// create a boolean array to keen track of visited nodes
			bool visited[this->v];
			// mark all node unvisited
			for(int i=0;i<this->v;i++)
				visited[i]=false;
			// for each node call dfsUtill if it is not visited
			for(int i=1;i<this->v;i++){
				if(!visited[i])
					dfsUtill(i,visited);
			}
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
        
};
int main(){
	Graph g(6);
	g.addEdge(1,2);
	g.addEdge(1,4);
	g.addEdge(4,6);
	g.addEdge(3,6);
	g.addEdge(2,5);
	g.addEdge(5,2);
	g.addEdge(6,3);
	g.addEdge(6,4);
	g.print();
	cout<<endl;cout<<endl;cout<<endl;cout<<endl;
	g.dfs(1);
	return 0;
}
