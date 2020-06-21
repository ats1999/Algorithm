//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Implement BFS algorithm using adjecency matrix.
//             Not_to_code = If A can do BFS then he can do DFS ==>DO_DO
// T.C         : O(N)
// A.S         : O(N)
//============================================================================
#include<bits/stdc++.h>
using namespace std;

// Note: 1 based indexing is used here. 
int const N=10;

int graph[N][N]={
    {0,1,1,1,0,0,0,0,0,0},
    {1,0,0,1,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,1,0,0},
    {1,1,0,0,1,0,0,0,0,0},
    {0,0,0,1,0,1,1,0,0,0},
    {0,0,0,0,1,0,1,0,0,0},
    {0,0,0,0,1,1,0,0,0,0},
    {0,0,1,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,1,0,1},
    {0,0,0,0,0,0,0,0,1,0}
};
/**
 * This function print graph. 
 */
void print(){
    for(int i=0;i<N;i++){
        cout<<i+1<<"->";
        for(int j=0;j<N;j++){
            if(graph[i][j])
            cout<<j+1<<"->";
        }
        cout<<endl;
    }
}

/**
 * This function performs bfs traversal on Graph. 
 */
void bfs(int src){
    queue<int>Q;
    Q.push(src);

    vector<bool>visited(N,false);
    visited[src]=true;
    cout<<src+1<<"->";
    while(!Q.empty()){
        int v=Q.front();
        Q.pop();

        // for all node adjacent to v;
        for(int i=0;i<N;i++){
            if(graph[v][i]==1&&!visited[i]){
                Q.push(i);
                cout<<i+1<<"->";
                visited[i]=true;
            }
        }
    }
}
//define
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
    //print();
    bfs(0);
    // expected output = 1->2->3->4->8->5->9->6->7->10->
	return 0;
}