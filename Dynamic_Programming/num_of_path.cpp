//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Count number of path from node a to node n using DP.
// T.C         : O()
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
/**
 * This function add a edge to the adjacency list.
 * @param {int} u - a node
 * @param {int} v - a node
 * @param {graph} adj - a empty graph.
 * @return {graph} a adjacency list.
 */
void addEdge(int u,int v,vector<vector<int>>&adj){
    adj[u-1].push_back(v-1);

    // bidirectional
    //adj[v].push_back(u);
}
/**
 * This function create the graph and makes a adjacency list.
 * @param {adj} adjacency list of the graph.
 * @param {int} numberOfNode
 * @param {int} e number of edge
 * @return {graph} a adjacency list.
 */
void createGraph(vector<vector<int>>&adj,int e){
    int u,v;
    while(e--){
        cin>>u>>v;
        addEdge(u,v,adj);
    }
}
/**
 * This function returns the number of path from start node to the destination node. 
 * 
 * Time complexity of this function becomes O(N^2) - bcz for each node we are trying to move all n 
 * nodes adjacent to it. 
 * 
 * @param {graph} adjaceny list of the graph
 * @param {int} u - a start node
 * @param {int} v - a end node
 * @return {int} the number of path from u to v.
 */
int numberOfPath(vector<vector<int>>adj,int u,int v){
    if(u==v){
        return 1;
    }

    int ans = 0;
    for(int node:adj[u]){
        ans += numberOfPath(adj,node,v);
    }

    return ans;
}

/**
 * This function returns the number of path from start node to the destination node. 
 * 
 * Time complexity of this function becomes O(N)
 * 
 * @param {graph} adjaceny list of the graph
 * @param {int} u - a start node
 * @param {int} v - a end node
 * @return {int} the number of path from u to v.
 */
int DP[1000];

int numberOfPathDP(vector<vector<int>>adj,int u,int v){
    // if path is already calculated then do not calculate it 
    if(DP[u]){
        return DP[u];
    }

    // if reached at the destination node then this can be included in the totel number of path
    if(u==v){
        return 1;
    }

    int ans = 0;
    // if from each adjacent node, 
    // we can reach destination node, then add 1 to the ans
    for(int node:adj[u]){
        ans += numberOfPathDP(adj,node,v);
    }

    // update memoization table
    DP[u] = ans;

    // return ans
    return ans;
}
// driver code
int main(){

    #ifndef ONLINE_JUDGE 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);  
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 

    memset(DP,0,sizeof DP);

	cout<<"Started\n";
	// I/O
	IOS;
    int numberOfNode,e;
    cin>>numberOfNode>>e;
    vector<vector<int>>adj(numberOfNode);
    createGraph(adj,e);
    
    // print the graph
    // for(int i=0;i<adj.size();i++){
    //     cout<<i+1;
    //     for(int node:adj[i])
    //         cout<<"->"<<node+1;
    //     cout<<endl;
    // }

    int numOfPath = numberOfPathDP(adj,1-1,6-1);
    cout<<"Number of path is: "<<numOfPath<<endl;

    
    
	cout<<"\nDone:)\n";
	return 0;
}