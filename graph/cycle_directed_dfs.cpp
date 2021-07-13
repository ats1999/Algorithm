//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Detect cycle in directed graph using DFS.
// 		https://www.youtube.com/watch?v=rKQaZuoUR4M
// T.C         : O()
// A.S         : O()
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define

// IDEA
// We will maintain three set OR state, white, gray and black. 
// We will start traversing/exploring from source vertex.
// There is no parent of source vertex then we pass parent as -1,
// similiarly for every vertex we pass it's associated parent. 

// every non explored vertices should be in white set initially. 
// first time when we reach any vertex, we will put it into gray set indecating that, it is under processing. 
// If any vertex is fully explored and there is no child to be explored, then it will be puted into black set
// black set containing fully explored vertex...

// while traverseing if we found any vertex which is in gray set, then there is cycle. 
// length of the cycle and node involved in the cycle is from the node forming cycle and up to we traversed so far. 
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
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
	static const char _WHITE='W';
	static const char _GRAY='G';
	static const char _BLACK='B';

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
		* This function detects if the graph contains cycle or not. 
		* @param src a node: starting point of traversing.
        * @return true if cycle in the graph, false otherwise..
		*/
		bool isCycle(int src){
			// create a boolean array to keen track of visited nodes
			vector<char>setIs(v);
			// mark all node unvisited
			for(int i=0;i<this->v;i++)
				setIs[i]=_WHITE;
			
			// Forest
			for(int i=0;i<this->v;i++)
				if(setIs[i]=_WHITE)
					if(dfsUtill(i,setIs))
						return true;
			
			return false;
		}
		/**
		* This function recersively call dfsUtill.
		* @param src a node:
		* @param setIs denote set of any node at a perticular instance of time. 
        * @return true if graph contins cycle, false otherwise
		*/
		bool dfsUtill(int src,vector<char>&setIs){
			// visit
			cout<<src+1<<" ";
			setIs[src]=_GRAY;
            // duering traversal , if we found any node which is already in _GRAY set
            // then this node is forming cycle. 

			// call dfsUtill for each adjacent node which is is _GRAY set
			for(auto adjNode=adj[src].begin();adjNode!=adj[src].end();adjNode++){
                // a cycle has been found
				if(setIs[*adjNode]==_GRAY)
                    return true;
				// if current node is not in _BLACK set
				if(setIs[*adjNode]!=_BLACK)
                // a cycle has been found in recursive call...
                if(dfsUtill(*adjNode,setIs))
                    return true;
			}
			// this node has been fully explored and now we will put it into _BLACK set
			setIs[src]=_BLACK;
            // cycle is not persent
            return false;
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
/*
	Not working on this input........
	4
	4
	1 2
	2 3
	1 4
	4 3
*/
	//g.print();
	if(g.isCycle(0)){
		cout<<"\nCycle detected!\n";
	}else{
		cout<<"\n No Cycle detected!\n";
	}
	return 0;
}