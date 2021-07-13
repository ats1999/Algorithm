//============================================================================
// Name        : cycle.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : To detect cycle in the graph. 
//              Jenny's leacture...
// Note		   : 0 based indexin used in this graph. 
// T.C		   : O(N) - Time taken to perform DFS. 
//============================================================================
#include<bits/stdc++.h>
using namespace std;

/*
https://www.geeksforgeeks.org/detect-cycle-in-a-directed-a-using-bfs/
https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
https://www.geeksforgeeks.org/detect-cycle-in-an-undirected-graph-using-bfs/
https://www.geeksforgeeks.org/detect-cycle-undirected-graph/

*/

// Idea is to use DFS algorithm to detects cycle. 
// while doing DFS, if we visit the any node that is already visited
// then graph  contains cycle.


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
		 * This function detects cycle in the graph.
		 * @param g input graph.
		 * @return true if graph contains cycle, false otherwise. 
		 */
		bool cycle(int src){
            int ar[v];
            //memset(ar,-1,sizeof ar);
            for(int i=0;i<v;i++){
                ar[i]=-1;
            }
            if(bfsUtill(src,ar)){
                return true;
            }else {
                return false;
            }
		}

        /**
         * This function returns true if graph contains cycle. 
         * @param g input graph.
         * @param visited array to keep track of visited vertices. 
         * @return true if there is cycle in the graph, false otherwise. 
         */
        bool bfsUtill(int src, int visited[]){

            // 0 indecates node has been pushed into queue
            // 1 indecates node has been poped from queue and processed
            // -1 indecates node has been not visited yet!

            visited[src]=0;

            queue<int>Q;
            Q.push(src);
            while(!Q.empty()){
                int v=Q.front();
                cout<<v+1<<"->";
                Q.pop();
                visited[v]=1;

                for(auto it=adj[v].begin();it!=adj[v].end();it++){
                    // current node is visited and we do not need to process it.
                    if(visited[*it]==1)
                        continue;
                    
                    // if current node is in underprocessing by any other node then there must be a cycle. 
                    if(visited[*it]==0)
                        return true;
                    // otherwise push, current node into queue. 
                    Q.push(*it);
                    visited[*it]=0;
                }
            }
            return false;
        }
};
// driver code
int main(){

    #ifndef ONLINE_JUDGE 
	    // For getting input from input.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin); 
	    // Printing the Output to output.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
    cout<<"Started\n";
    int N,E;
    cin>>N>>E;
	Graph g(N); 
	
    while(E--){
        int u,v;
        cin>>u>>v;
        g.addEdge(u-1,v-1); // u-1/v-1 Bcz.. 0 based indexing used in the graph.... and 1 based repersention is used....
    }

    // Graph g(4);
    // g.addEdge(0,1);
    // g.addEdge(1,2);
    // g.addEdge(2,3);
    // g.addEdge(3,1);
	//g.print();

     if(g.cycle(0))
        cout<<"\nGraph contains cycle\n";
    else cout<<"\nGraph does not contains cycle. ";
	return 0;
}

