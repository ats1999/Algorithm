//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Implemention o fenwick tree. 
//              https://www.youtube.com/watch?v=CWDQJGaN1gY
//              https://www.geeksforgeeks.org/two-dimensional-binary-indexed-tree-or-fenwick-tree/
// T.C         : O(nlog(n)) for making fenwick tree. Rest of the operation cost O(log(n))
// A.S         : O(n) - to store  fenwick tree.
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
int N=4;
/**
 * This function finds next index to fill.
 * @param index current index.
 * @return next index that could be affected by 'index'
 */
int getNextIndex(int index){
    index += (index&-index);
    return index;
}
/**
 * This function takes an index as argument and return it's parent.
 * @param index
 * @return parent of index
 */
int getParent(int index){
    index -= (index&-index);
    return index;
}
/**
 * This fnction takes an array and an empty fenwick tree, then it builds fenwick tree out of that array.
 * @param ar[] input array
 * @param n size of ar[]
 * @param fenwick empty fanwick to build
 */
void buildFenwick(int ar[],int fenwick[],int n){
    
}
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
    int N=4;
    int mat[N][N] = {{1, 2, 3, 4}, 
                    {5, 3, 8, 1}, 
                    {4, 6, 7, 5}, 
                    {2, 4, 8, 9}};
    int BIT[N+1][N+1]; 
    buildFenwick(mat, BIT); 
	return 0;
}