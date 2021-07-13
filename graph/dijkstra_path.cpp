//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Implemention of standred Dijkstra algorithm...
// Note        : 0 based indexing using in this program..
// T.C         : O()
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;
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
	vector<pair<int,int>>*adj;
	public:
		/**
         * Constructor to initialize the graph.
         * @param v an integer: number of nodes in the graph
         */
		Graph(int V){
			this->v=V;
			this->adj=new vector<pair<int,int>>[V];
		}
		
		/**
         * This function add a new edge to the graph.
         * @param u an integer: representing a node in the graph.
         * @param v an integer: representing a node in the graph.
         * @param biDir a bool: true denotes bidirectional edge, unidirectional otherwise.
         */
		void addEdge(int u,int v,int w,bool biDir=true){
            adj[u].push_back(make_pair(v,w));
            if(biDir)
                adj[v].push_back(make_pair(u,w));
        }
        /**
         * This function print list represention of the graph.
         */
        void print(){
            // for every vertex
            for(int i=0;i<this->v;i++){
				cout<<i<<"-> ";
                // every connected edge from vertex
                for(auto node:adj[i]){
                    cout<<node.first<<"("<<node.second<<"),  ";
                }
                cout<<endl;
            }
        }

        void dijkstra(int src,int dist[],int path[]){
            vector<bool>visited(v,false);
            // w,u,v
            set<pair<int,int>>Set;

            visited[src]=true;
            path[src]=-1;
            // mark distance of all node to INF initially
            for(int i=1;i<v;i++){
                Set.insert(make_pair(INT_MAX,i));
            }

            for(int i=0;i<v;i++)
                dist[i]=INT_MAX;
            dist[src]=0;

            // distance of source node is zero.
            Set.insert(make_pair(0,src));

            while(!Set.empty()){
                auto v=Set.begin();

                for(auto adjNode:adj[v->second]){
                    if(!visited[adjNode.first])
                    // relax
                    if(dist[adjNode.first]>dist[v->second]+adjNode.second){
                        dist[adjNode.first]=dist[v->second]+adjNode.second;
                        path[adjNode.first]=v->second;
                    }
                }
                visited[v->second]=true;
                Set.erase(v);
            }
        }
};
// driver code
int main(){
	cout<<"Started\n";
	// I/O
	IOS;

    #ifndef ONLINE_JUDGE 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);  
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
	int n,v;
	cin>>n>>v;
	Graph g(n); // biirectional

    // get input
	while(v--){
		int u,v,w;
        cin>>u>>v>>w;
		g.addEdge(u,v,w);
	}

    // operate
	//g.print();
    
    int dist[n],path[n];
    g.dijkstra(0,dist,path);

    cout<<"Distances====>>\n";
    for(int i=0;i<n;i++){
        cout<<i<<"->"<<dist[i]<<endl;
    }
	return 0;
}