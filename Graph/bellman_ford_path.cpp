//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Implemention of Bellman ford algorithm for computing path also. 
// T.C         : O(N^2) avarage case, O(N^3) when graph is complete graph
// A.S         : O()
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

// IDEA
// Retraving path is basedd upon the fact that, if node A is getting relaxed by node B
// then sortest path is comeing from node A.. 

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

	// start vertex, end vertex and cost to reach(distance)
	vector<pair<int,pair<int,int>>>*edgeList;
	public:
		/**
         * Constructor to initialize the graph.
         * @param v an integer: number of nodes in the graph
         */
		Graph(int V){
			this->v=V;
			this->edgeList=new vector<pair<int,pair<int,int>>>;
		}
		
		/**
         * This function add a new edge to the graph.
         * @param u an integer: representing a node in the graph.
         * @param v an integer: representing a node in the graph.
		 * @param cost an integer: representing cost from reaching node u to v
         * @param biDir a bool: true denotes bidirectional edge, unidirectional otherwise.
         */
		void addEdge(int u,int v,int cost,bool biDir=false){
            edgeList->push_back(make_pair(u,make_pair(v,cost)));
            if(biDir)
                edgeList->push_back(make_pair(v,make_pair(u,cost)));
        }
        /**
         * This function print list represention of the graph.
         */
        void print(){
                // every connected edge from vertex
                for(auto it=edgeList->begin();it!=edgeList->end();it++){
					cout<<it->first+1<<"->"<<it->second.first+1<<","<<it->second.second<<endl;
				}
        }
        /**
         * This function returns sortest path from source vertex to the given node. 
         * @param node 
         * @param predcessor[]
         */
        void path(int node,int predcessor[]){
            vector<int>path;
            path.push_back(predcessor[node]);
            while(predcessor[node]!=-1){
                node=predcessor[node];
                path.push_back(predcessor[node]);
            }
        }
        /**
         * This function relax the given edge if it can be. 
         * @param u distance of u from source
         * @param v distance of v from source
         * @param w weight of edge u->v
         * @return minimum of u+w & v;
         */
        int relax(int u,int v,int w){
            if(v>u+w){
                return u+w;
			}
            return v;
        }

        /**
         * This function checks wheather graph contains -VE weight cycle or not.
         * @param dist[] array of distance of every node from source.
         * @return true if graph contains -VE weight cycle =, false otherwise. 
         */
        bool isCycle(int dist[]){
            for(auto it=edgeList->begin();it!=edgeList->end();it++){
					if(dist[it->second.first]>dist[it->first]+it->second.second)
						return true;
			}
            return false;
        }
		/**
		 * This function is a implemention of standered bellman ford algorithm. 
		 * @param path[] array which contains sortest path from source node to all other nodes. 
		 * @param src source vertex
		 * @param N number of nodes in the graph. 
		 * @return true if the graph contains -VE weight cycle and sortest path for all the node can not be constructed, false otherwise. 
		 */
		bool bellmanFord(int dist[],int predcessor[],int src,int N){
			// initially initilize each node distance to infinity... 
			for(int i=0;i<N;i++){
				dist[i]=INT_MAX-10000;// overflow...
                predcessor[i]=-1;
			}

			// distance of source vertex from source is zero. 
			dist[src]=0;

            // SPFA flag to abort the further processing, if further processing can not give any relexations...
			bool abort=false;
			// repete this process N-1 times
			for(int i=0;i<N-1;i++){
				// go through every edge and relax that edge
				for(auto it=edgeList->begin();it!=edgeList->end();it++){
					if(dist[it->second.first]>dist[it->first]+it->second.second){
						dist[it->second.first]=dist[it->first]+it->second.second;
                        predcessor[it->second.first]=it->first;
                        abort=true;
                    }
				}
                // if in the current pass any vertex is not going to relax then
                // in further passes, any vertex can't be relaxed...
                if(!abort)
                    break;
			}

            // check for cycle of -VE weight
            if(isCycle(dist))
                return true;
			
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
        int u,v,w;
        cin>>u>>v>>w;
        g.addEdge(u-1,v-1,w); // u-1/v-1 Bcz.. 0 based indexing used in the graph.... and 1 based repersention is used....
    }
	int dist[N];

    int predcessor[N];
	//g.print();

	if(g.bellmanFord(dist,predcessor,0,N)){
        cout<<"Graph contains -VE weight cycle..\1n";
    }else{
        for(int i=0;i<N;i++){
			cout<<i+1<<" "<<dist[i]<<" "<<endl;//=INT_MAX-10000;// overflow...
		}
    }
    
	return 0;
}