//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Build segment tree for range queries. 
// T.C         : O()
// A.S         : O()
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

/**
 * This function return sum in the range.
 * @param tree sigment tree
 * @param start start of the sigment
 * @param end end of the sigment
 * @param queryStart Start of the query
 * @param queryEnd End of the query
 * @param v current sigment value. 
 */
int getSumInRange(int tree[],int start,int end,int queryStart,int queryEnd,int v){
    // three cases in the query
    // if query completely overlaped in the current sigment then it is going to contribute to the ans...
    // if query do not overlaped then it is not going to contribute into the answer...
    // if query partially overlapped then ask to the right and left chield..

    int mid=(start+end)/2;

    // no overlap
    if(queryStart>end||queryEnd<start)
        return 0;

    // partial overlap
    if(queryStart>start||queryEnd<end)
        return getSumInRange(tree,start,mid,queryStart,queryEnd,v*2+1)+getSumInRange(tree,mid+1,end,queryStart,queryEnd,v*2+2);

    // complete overlap
    // when queryStart<=start && queryEnd>=end
    return tree[v];
}
/**
 * This function builds a segment tree from start.
 * @param ar[] input array
 * @param tree[] sigment tree of ar[].
 * @param start start of the range.
 * @param end end of the range.
 * @param v node of the tree.
 */
void build(int ar[],int tree[],int start,int end,int v){
    if(start==end){
        tree[v]=ar[start];
        return;
    }
    else{ 
        int mid=(start+end)/2;
        build(ar,tree,start,mid,v*2+1);
        build(ar,tree,mid+1,end,v*2+2);
        tree[v]=tree[v*2+1]+tree[v*2+2];
    }
}
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
    /*
    We are given an array A[0,1,...,N] and some queries to perform on that array. 
    For example, we are  asked to find minimum element in the given range A[l,r].

    1. We can do this by traversing from l to r and compute minimum.
       T.C=O(n) - in worst case l could be 0 and r could be n-1.
       A.S = O(1).
    2. We can create a 2D array, and store all range queries in the upper traingular matrix 
        of newely created array. 
    
        T.C=O(n^2) -Time taken to build the 2D array (pre-computing).
        T.C=O(1) - perform a query.
        T.C=O(n^2) - when there is any update, then we have to build the entire 2D array from scratch, in the worst case. 
        A.S = O(n^2) - store 2D array.
    
    3. There is spacal data structure, which can do the same in O(log(n)) time, called sigment tree.
    */
    int n=6;
    // cin>>n;
    int ar[n]={1,2,3,4,5,6};

    // for(int i=0;i<n;i++){
    //     cin>>ar[i];
    // }
    // int tree[4*n];
    int tree[4*n];
    memset(tree,0,sizeof tree);
    build(ar,tree,0,n-1,0);
    
    // for(int i=0;i<4*n-1;i++)
    for(int i=0;i<4*n;i++){
        cout<<tree[i]<<" ";
    }
    cout<<endl;

    int s,e;
    cin>>s>>e;
    cout<<getSumInRange(tree,0,n-1,s,e,0);
    
    
	return 0;
}