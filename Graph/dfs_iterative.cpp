//============================================================================
// Name        : dfs_iterative.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Implemention iterative DFS algorithm. 
// Note		   : 1 based indexing used in this graph.
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
			// call dfsUtill()
					dfsUtill(src,visited);
		}
		/**
		* This function iteratively do DFS.
		* @param src a node:
		* @param visited a bool[]:
		*/
		void dfsUtill(int src,bool visited[]){
			// cerate a stack for DFS
			stack<int>Stack;
			// push src
			Stack.push(src);
			
			while(!Stack.empty()){
				int v=Stack.top();
				Stack.pop();
				if(!visited[v]){
					cout<<"->"<<v;
					visited[v]=true;
					for(auto it=adj[v].begin();it!=adj[v].end();it++){
						Stack.push(*it);
					}
				}
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
