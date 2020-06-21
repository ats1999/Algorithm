//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Find strongly commented components of undirected graph. 
// T.C         : O(N)
// A.S         : O()
// Note:        1 based indexing has been used in this graph. 
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define

// SCC can be found in undirected graph in one DFS/BFS traversal. 
// We'll do traversal for every node. 
// because, BFS/DFS can traverse a connected components. 
// It can not reach to the other component from another component. 
// That's why, we need to do BFS/DFS traversal for every node in the graph. 

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
		void addEdge(int u,int v,bool biDir=true){
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

        /**
         * This function finds strongly connected component of the given graph. 
         * @param g input graph.
         */
        void scc(Graph g){
            vector<bool>visited(this->v,false);
            // for each node in the graph do BFS
            for(int i=1;i<this->v;i++){
                if(!visited[i]){
                    cout<<"Component..\n";
                    this->bfs(i,visited);
                    cout<<endl;
                }
            }
        }

        /**
         * This function traverse the given graph using BFS traversal technique.
         * @param src a node: function starts traversing from this node.
         */
        void bfs(int src,vector<bool>&visited){
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
};
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
// driver code
int main(){
	cout<<"Started\n";
	// I/O
	IOS;
    #ifndef ONLINE_JUDGE 
	    // For getting input from input.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin); 
	    // Printing the Output to output.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif
    Graph g(10);

    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(9,8);
    g.scc(g);
	return 0;
}