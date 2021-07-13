//============================================================================
// Name        : mst_kruskal.cpp
// Author      : Rahul
// Version     : 2.0
// Copyright   : Everyone freely can use and distribute it.
// Description : Find MST of given weighted and connected graph using Prims algorithm. 
//                - 0 based indexing and 1 based repersention has been used in this graph.  
// 			   - Edges are bi-directional
// T.C		   : O(Nlog(N)) - Time taken to sort the edge list. 
//============================================================================
#include<bits/stdc++.h>
using namespace std;
#include "../Graph/disj_set.h"
/**
 * This function creates the graph.
 * This is a utility function. 
 * @param {int} numberOfNode
 * @param {int} numberOfEdge
 * @return {vector<vector<pair<int,int>>>} vector of pairs containing grapg.
 */
vector<vector<pair<int,int>>> createGraph(int numberOfNode,int numberOfEdge){
    vector<vector<pair<int,int>>>adj(numberOfNode);
    // reading input
	int start, end, weight;
	while( numberOfEdge-- ){
		cin>> start >> end >> weight ;
        // create edge
        adj[start-1].push_back(make_pair(end-1,weight));
        // bidirectional
        adj[end-1].push_back(make_pair(start-1,weight));
	}
    return adj;
}
/**
 * This function find MST of the given graph using prims algorithm.
 * @param {int} numberOfNode
 * @param {int} numberOfEdge
 * @return {int} mst of the given graph.
 */
int mstWeight(int numberOfNode,int numberOfEdge,int src){
    // create graph
    vector<vector<pair<int,int>>>adj=createGraph( numberOfNode, numberOfEdge);
    
    int mst = 0;

    // create a priority queue to accesss the edge with minimum weight all the time.
    priority_queue<pair<int,pair<int,int>>>PQ;
    // put all node adjecent to the start node in priority queue
    for(auto it = adj[src].begin();it!=adj[src].end();it++){
        PQ.push(make_pair(-it->second,make_pair(src,it->first)));
    }

    // create a disjoint set
    DisjSet set(numberOfEdge);
    // number of node that are currently processed
    bool isProcessedNode[numberOfNode];
    memset(isProcessedNode, false, sizeof isProcessedNode);
    // If processed node = NumberOfNode - 1
    int processedEdge = 0;
    isProcessedNode[src] = true;

    while(!PQ.empty()){
        auto edge = PQ.top();
        PQ.pop();

        // print the PQ
        // cout<<edge.second.first+1/*Start Node*/
        // <<"->"<<edge.second.second+1/*End Node*/
        // <<"="<<abs(edge.first)/*Weight Node*/<<endl;

        int u = edge.second.first;
        int v = edge.second.second;
        int w = edge.first;

        if(!set.areInSameSet(u,v)){
            set.unite(u,v);
            mst += abs(w);
            //cout<<"Including: "<<u+1<<"->"<<v+1<<endl;
            // if node u is not processed, then enqueue all of it's adjacent nodes
            if(!isProcessedNode[u]){
                for(auto it = adj[u].begin();it != adj[u].end();it++){
                    PQ.push(make_pair(-it->second/*weight*/,
                    make_pair(u/*Start node of the edge*/,
                    it->first/*End node of the edge*/)));
                }
            }

            // if node v is not processed, then enqueue all of it's adjacent nodes
            if(!isProcessedNode[v]){
                for(auto it = adj[v].begin();it != adj[v].end();it++){
                    PQ.push(make_pair(-it->second/*weight*/,
                    make_pair(v/*Start node of the edge*/,
                    it->first/*End node of the edge*/)));
                }
            }    
        }else{
            //cout<<"Not including: "<<u+1<<"->"<<v+1<<endl;
        }
    }
    return mst;
}

int main(){
	
	#ifndef ONLINE_JUDGE 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);  
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
	
	cout<<"Start\n";
	int numberOfNode,numberOfEdge;
	cin>>numberOfNode>>numberOfEdge; 
    int startNode = 1;
    int mst = mstWeight(numberOfNode,numberOfEdge,startNode-1);

	cout<<"\n Weight is: "<<mst;
	cout<<"\nEnd\n";
}
