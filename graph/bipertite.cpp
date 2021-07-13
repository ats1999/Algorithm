//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Check weather a graph is bipertitte or not. 
//              https://en.wikipedia.org/wiki/Bipartite_graph
// NOTE: It can also be done by DFS, checkout the above link..
// T.C         : O()
// A.S         : O()
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

// idea is to use BFS algorithm to check bipertitness of any graph. 
// At any instance of time, each node can have three states.
//          1. No color
//          2. Red color
//          3. Black color
// using BFS we can check, if every two adjacent vertices can be colored with different color or not. 

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
    static const char _NO_COLOR='N';
    static const char _RED='R';
    static const char _BLACK='B';
    
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
            for(int i=0;i<this->v;i++){
                cout<<i+1<<"->";
                // every connected edge from vertex
                for(int node:adj[i]){
                    cout<<node+1<<"->";
                }
                cout<<endl;
            }
        }

        /**
         * This function traverse the graph and check wether this graph is bipertite or not. 
         * @param src a node: function starts traversing from this node.
         */
        bool isBipertite(int src){
            // create a array of boolean to keep track of visited nodes.
            vector<char>colorOf(v);

            // initially every node is not colored
            for(int node=0;node<v;node++)
                colorOf[node]=_NO_COLOR;

            if(bfsUtill(src,colorOf)){
                cout<<"\nGraph is bipertite\n";
            }else{
                cout<<"\nGraph is not bipertite\n";
            } 
        }

        bool bfsUtill(int src,vector<char>&colorOf){
            // visited[0]=true;
            // make a queue and insert src into it
            queue<int>q;
            q.push(src); // insert src into queue
            colorOf[src]=_RED;
            // mark first node as visited
            while(!q.empty()){
            	int node=q.front();
            	// visit
            	cout<<node+1<<" ";
            	// remove this node from queue
            	q.pop(); 
            	// visit every node adjacent to node 'node' 
            	// if that node not visited then visit and enque it.
            	for(int adjNode:adj[node]){
            		if(colorOf[adjNode]==_NO_COLOR){
            			if(colorOf[node]==_RED)
                            colorOf[adjNode]=_BLACK;
                        else colorOf[adjNode]=_RED;
                        
            			q.push(adjNode);
					}else {
                        if(colorOf[node]==colorOf[adjNode])
                            return false;
                    }
				}
			}
            return true;
        }
};
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
    int N,E;
    cin>>N>>E;
	Graph g(N); 
	
    while(E--){
        int u,v;
        cin>>u>>v;
        g.addEdge(u-1,v-1); // u-1/v-1 Bcz.. 0 based indexing used in the graph.... and 1 based repersention is used....
    }
    g.isBipertite(0);

    /*
    6
7
1 2
2 3
3 6
4 1
4 5
5 2

// check whether this input is bipertite or not. 
// because there is two component
*/
    //g.print();
	return 0;
}