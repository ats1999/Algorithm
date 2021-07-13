//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Find topological sort ordering of the given graph. 
// T.C         : O()
// A.S         : O()
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

// An acyclic graph always has a topological sort. However, if the graph contains
// a cycle, it is not possible to form a topological sort, because no node of the cycle
// can appear before the other nodes of the cycle in the ordering. It turns out that
// depth-first search can be used to both check if a directed graph contains a cycle
// and, if it does not contain a cycle, to construct a topological sort.

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
    
    static const char _UNPROCESSED='0';
    static const char _UNDER_PROCESSING='1';
    static const char _PROCESSED='2';

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
                    cout<<node+1<<" ";
                }
                cout<<endl;
            }
        }

        /**
		* This function is for DFS traversal for graph.
		* @param src a node: starting point of traversing.
		*/
		void topologicalSort(int src){
			// mark all node unvisited
            vector<char>stateOf(v);
            vector<int>topologicalOrder;

            // initially state of every node is _UNPROCESSED
			for(int i=0;i<this->v;i++)
				stateOf[i]=_UNPROCESSED;
            
            // for each _UNPROCESSED node call dfsUtill();
            for(int i=0;i<this->v;i++)
                if(stateOf[i]==_UNPROCESSED){
                    if(!dfsUtill(i,stateOf,topologicalOrder))
                        cout<<"Topological sort can not be performed!\n";
                    else cout<<"Topological sort has been performed!\n";
                }
					
            reverse(topologicalOrder.begin(),topologicalOrder.end());

            for(int i:topologicalOrder)
                cout<<i+1<<" ";
		}
		/**
		* This function recersively call dfsUtill.
		* @param src a node:
		* @param stateOf a array which contains state of each node at a perticular instance of time.
		*/
		bool dfsUtill(int src,vector<char>&stateOf,vector<int>&topologicalOrder){
			// visit
			cout<<src+1<<" ";

            // at any instance of time, any node can have state _UNPROCESSED,_PROCESSED and _UNDER_PROCESSING
            // duering traversal if we found any _UNDER_PROCESSING node then this graph contains cycle and it is not possible. 
            // to construct topologicall  sort

            // once we traversed each adjacent of any node, then this node will be marked _PROCESSED
			stateOf[src]=_UNDER_PROCESSING;
			// call dfsUtill for each adjacent node(unvisited)
			for(auto it=adj[src].begin();it!=adj[src].end();it++){
				if(stateOf[*it]==_UNDER_PROCESSING)
					return false;

                if(stateOf[*it]==_PROCESSED)
                    continue;

                if(!dfsUtill(*it,stateOf,topologicalOrder))
                    return false;
			}

            stateOf[src]=_PROCESSED;
            topologicalOrder.push_back(src);

            return true;
		}
};
// driver code
int main(){
	cout<<"Started\n";
	// I/O
	IOS;
    // #ifndef ONLINE_JUDGE 
	//     // For getting input from input.txt file 
	//     freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin); 
	//     // Printing the Output to output.txt file 
	//     freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    // #endif 
    cout<<"Started\n";
    int N,E;
    cin>>N>>E;
	Graph g(N); 
	
    while(E--){
        int u,v;
        cin>>u>>v;
        g.addEdge(u-1,v-1); // u-1/v-1 Bcz.. 0 based indexing used in the graph.... and 1 based repersention is used....
    }

    g.topologicalSort(0);
   //g.print();
	return 0;
}