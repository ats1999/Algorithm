//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Detects cycle in the graph using floyd cycle detection algorithm. 
// T.C         : O()
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

bool isCycle(vector<int>&succ,int src){
    int a,b;
    a = b = src;
    a = succ[a];
    b = succ[succ[b]];

    while(a!=b){
        a = succ[a];
        b = succ[succ[b]];
    }   
}
// driver code
int main(){
	cout<<"Started\n";
	// I/O
	IOS;
    #ifndef ONLINE_JUDGE 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);  
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
    int n,e;
    cin>>n>>e;

    // this is a successor graph
    // every node has only one outgoing edge.
    // out dgree of every node is one.
    vector<int>succ(n+1,0);
    int u,v;
    while(e--){
        cin>>u>>v;
        succ[u]=v;
    }



	cout<<"\nDone:)\n";
	return 0;
}