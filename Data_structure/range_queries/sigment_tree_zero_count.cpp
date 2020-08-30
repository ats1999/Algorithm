//============================================================================
// Name        : sigment_tree_zero_count.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Count the number of zero appears in any subsigment.
//               Find kth zero as.. IN: 1,2,0,3,0.. then first zero would be at 2nd index.
// T.C         : O()
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

/**
 * @param {tree} - Sigment tree
 * @param {start} - start  of the tree. 
 * @param {end} -  end of the  tree. 
 * @param {k} -  return the kth zero in the original array.
 * @param {v} - this is the vertex of the tree, whose value will be considered if critria matches.
 * @return {index of kth zero} if kth zero is persent then return the index of kth zero, -1 otherwise.
 */
int queryKthZeroIndex(int tree[],int start, int end, int k, int v){
    // if current vertex do not contain atleat k zero, then kth zero is not persent in the original array
    if(tree[v] < k)
        return -1;

    if(start == end) 
        return start;
    // if left sub-segment contain atleast k zero, then move down to left sub-sigment. 
    // otherwise move down to the right sub-sugment
    int mid = (start + end)/2;
    if(tree[2*v+1]>=k)
        return queryKthZeroIndex(tree, start, mid,k,2*v+1);
    else return queryKthZeroIndex(tree, mid+1, end,k-tree[2*v+1],2*v+2);
}
/**
 * @param {tree} - Sigment tree
 * @param {queryStart} - starting range of the query.
 * @param {queryEnd} - ending range of the query
 * @param {start} - start  of the tree. 
 * @param {end} -  end of the  tree. 
 * @param {v} - this is the vertex of the tree, whose value will be considered if critria matches.
 * @return {numberOfZero} number of zero in the start and end. 
 */
int queryCountZero(int  tree[], int queryStart, int queryEnd, int start, int end, int v){
    // no overlap case
    if(queryStart > end || queryEnd < start)
        return 0;

    // partial overlap
    if(queryStart > start || queryEnd < end){
        int mid = (start + end)/2;
        int leftSigmentZero = queryCountZero(tree, queryStart, queryEnd, start, mid, 2*v+1);
        int rightSigmentZero = queryCountZero(tree, queryStart, queryEnd, mid+1, end, 2*v+2);
        return leftSigmentZero + rightSigmentZero;
    }

    // complete overlap
    //if(queryStart >= start && queryEnd <= end)

    // do not need to check the  above condition
    // this is the last condition, that will definetly meet
    return tree[v];
}
/**
 * @param {ar} - input array
 * @param {tree} - output sigment tree by build function.  
 * @param {start} - start of the array range
 * @param {end} - end of the array range
 * @param {v} - index of  the tree, where the current element should be pushed.
 */
void build(int ar[],int tree[], int start, int end, int v){
    if(start == end){
        tree[v] = ar[start] == 0 ? 1 : 0;
        return;
    }

    int mid = (start + end)/2;
    build(ar, tree, start, mid, 2*v+1);
    build(ar,tree, mid+1, end, 2*v+2);
    tree[v] = tree[2*v+1] + tree[2*v+2];
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
    int n;
    cin>>n;
    int ar[n];
    for(int i=0; i<n; i++){
        cin>>ar[i];
    }
    int tree[4*n];
    build(ar,tree,0,n-1,0);

    int k;
    cin>>k;
    cout<<queryKthZeroIndex(tree,0,n-1,k,0);
	cout<<"\nDone:)\n";
	return 0;
}