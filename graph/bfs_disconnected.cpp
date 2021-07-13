//============================================================================
// Name        : bfs_disconnected.cpp
// Author      : Rahul
// Version     : 2.0
// Copyright   : Everyone freely can use and distribute it.
// Description : BFS traversal of disconneted graph
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
		* This function will call dfsUtill for all unvisited node once.
		**/
		void bfs(){
			 // create a array of boolean to keep track of visited nodes.
            bool visited[this->v];
            for(int i=0;i<this->v;i++)
            	visited[i]=false;
            // for each node in graph
            for(int i=1;i<this->v;i++){
            	if(!visited[i])
            	bfsUtill(i,visited);
			}
		}
        /**
         * This function traverse the given graph using BFS traversal technique.
         * @param src a node: function starts traversing from this node.
         */
        void bfsUtill(int src, bool visited[]){
            // make a queue and insert src into it
            queue<int>q;
            q.push(src); // insert src into queue
            // mark first node as visited
            visited[src]=true;
            while(!q.empty()){
            	int node=q.front();
            	// visit
            	cout<<node<<" ";
            	// remove this node from queue
            	q.pop(); 
            	// visit every node adjacent to node 'node' 
            	// if that node not visited then visit and enque it.
            	for(int adjNode:adj[node]){
            		if(!visited[adjNode]){
            			visited[adjNode]=true;
            			q.push(adjNode);
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
	g.bfs();
	return 0;
}
