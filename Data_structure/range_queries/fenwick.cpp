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
#include "C:\Users\Rahul kumar\desktop\Algorithm\print.h"
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

/**
 * This function finds next index to fill.
 * Time complexity of this function is O(1)
 * @param index current index.
 * @return next index to add
 */
int getNext(int index){
    // get 2's complement of index.
    // AND with original number
    // add it to the original number. 

    index += (index&-index);
    return index;
}
/**
 * This function takes an index as argument and return it's parent.
 * Time complexity of this function is O(1)
 * @param index
 * @return parent of index
 */
int getParent(int index){
    // efficient way 
    // 1. get 2's complement index
    // 2. AND with original index.
    // 3. subtract from the original index. 
    
    // NOT EFFICIENT
    // 1. parent of index i= convert i into it's binary repersention
    // 2. flip the right-most set bit
    // 3. then check it's decimal value. 

    // Ex- find parent of 8
    //         binary repersention of 8 is 1000
    //         filp the right most bit- 0000=0
    //     parent of 8 is zero. 

    // Ex- find parent of 7
    //         binary of 7 is 111
    //         flip the right most bit - 110 = 6
    //     parent of 7 is 6
     
     index-=(index&-index);
     return index;
}

/**
 * This function add a specific value to the given index.
 * Time complexity of this function is O(log(n))
 * 
 * @param index index where value to be add.
 * @param val value to be added
 * @param fenwick[] fenwick tree we have to built. 
 * @param last last index of fenwick[]
 */
void add(int index,int val,int last,int fenwick[]){
    // add value to the current index
    fenwick[index]+=val;

    // get next index that could be affected due to adding this to the current index.
    // until next index is less than max index of fenwick
    // at every next index of fenwick add val
    index = getNext(index);
    while(index<=last){
        fenwick[index]+=val;
        index=getNext(index);
    }     
}
/**
 * This fnction takes an array and an empty fenwick tree, then it builds fenwick tree out of that array.
 * Time complexity of this function is O(nlog(n)), because for each element i of input array, 
 * we are doing log(n) operation. Idea is that, we are finding next. For any number 
 * there could be max log(n) set bit, where n is number. For every set bit, we have to add value to the perticular inedx.
 * @param ar[] input array
 * @param n size of ar[]
 * @param fenwick empty fanwick tree to build
 */
void buildFenwick(int ar[],int fenwick[],int n){
    // 1. assume that tree array is 1 indexed
    // every number can be repersented by sum of power of 2
    // Ex-  10= 2^3+2^1
    //      fenwic tree use this information to store the prefix sum.

    // at index i of fenwic tree store the index j value of original array .
    // Ex- let i=6
    // i can be repersented as 2^2+2^1
    // so at index 6 of fenwic tree, store the value sum of the range of 4,5, starting from index to 1 more. 
    for(int i=0;i<=n;i++)
        fenwick[i]=0;

    for(int i=0;i<n;i++){
        add(i+1,ar[i],n,fenwick);
    }
}

/**
 * This function return sum of all element of the original array, in the given range.
 * Time complexity of this function is O(2*log(n)). constant factor??
 * @param start start index of range
 * @param end end index of range.
 * @param fenwick[] fenwick tree
 * @return sum in range start - end
 */
int sumInRange(int start,int end,int fenwick[]){
    // 1 based indexing. 
    // get sum from A[0..end]
    int rightSum=fenwick[end];

    int parent = getParent(end);
    while(parent>0){
        rightSum+=fenwick[parent];
        parent = getParent(parent);
    }

    // get sum from A[0..start]
    int leftSum = fenwick[start];
    parent = getParent(start);
    while(parent>0){
        leftSum+=fenwick[parent];
        parent = getParent(parent);
    }

    // return actual sum
    return rightSum-leftSum;
}
/**
 * This function return sum of all element of the original array, in the given range.
 * Time complexity of this function is O(log(n)).
 * @param index end index of range.
 * @param fenwick[] fenwick tree
 * @return sum in range start - end
 */
int sumUpTo(int index,int fenwick[]){
    // 1 based indexing. 
    int sum=fenwick[index];

    int parent = getParent(index);
    while(parent>0){
        sum+=fenwick[parent];
        parent = getParent(parent);
    }
    return sum;
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
    printAr(fenwick,9);
    // int s,e;
    // cin>>s>>e;
    // cout<<sumInRange(s-1,e,fenwick);
	return 0;
}