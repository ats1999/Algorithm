//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Implemention o fenwick tree. 
//              https://www.youtube.com/watch?v=CWDQJGaN1gY
// T.C         : O(nlog(n)) for making fenwick tree. Rest of the operation cost O(log(n))
// A.S         : O(n) - to store  fenwick tree.
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

/**
 * This function finds next index to fill.
 * @param index current index.
 * @param last last index of the array.
 * @return next index if it is in range, -1 otherwise. 
 */
int getNextIndex(int index,int last){

    return 0;
}
/**
 * This function takes an index as argument and return it's parent.
 * @param index
 * @return parent of index
 */
int getParent(int index){
     
}
/**
 * This fnction takes an array and an empty fenwick tree, then it builds fenwick tree out of that array.
 * @param ar[] input array
 * @param n size of ar[]
 * @param fenwick empty fanwick to build
 */
void buildFenwick(int ar[],int fenwick[],int n){
    memset(fenwick,0,sizeof fenwick);

    for(int i=0;i<n;i++){
        
    }
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
    int ar[8]={1,4,4,16,6,7,4,29};
    int fenwick[8+1];
    buildFenwick(ar,fenwick,8);
	return 0;
}