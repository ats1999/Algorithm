//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Count frequency of x element from sorted array
//       For ex: Ar = [1,2,3,3,3,4,9], x=3
//       Output: 3
// T.C         : O(logn)
// A.S         : O(1)
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
/*
================
-> A naive approach would be to find first index of x
-> start counting, till x
-> return answer

T.C: O(N)

=====================
-> A better approach is to use binary search
-> find leftmost and rightmost index of x in logn time
-> then return rightIdx-leftIdx+1
*/

/**
 * Get leftmost occurence of x in ar
 * @param {array} ar input array
 * @param {int} x input number
 * @param {int} n size of ar
 * @return {int} leftmost index of x in ar, -1 if x is not in the array
 */
int getLeftMostIdx(int ar[], int x, int n){
    int l=0, r=n-1;
    bool flag = false;
    while(l<=r){
        int mid = (l+r)/2;
        // // if mid is the right answer then return mid
        if(ar[mid] == x){
            if((mid == 0) || (ar[mid-1]<x)) 
                return mid;
        }

        // // iterate over left or right half
        // // depending on the condition
        if(ar[mid]<x){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }

    // if index not found
    if(!flag) return -1;
}

/**
 * Get rightmost occurence of x in ar
 * @param {array} ar input array
 * @param {int} x input number
 * @param {int} n size of ar
 * @return {int} rightmost index of x in ar, -1 if x is not in the array
 */
int getRightMostIdx(int ar[], int x, int n){
    int l=0, r=n-1;
    bool flag = false;
    while(l<=r){
        int mid = (l+r)/2;
        // // if mid is the right answer then return mid
        if(ar[mid] == x){
            if((mid == (n-1)) || (ar[mid+1]>x)) 
                return mid;
        }

        // // iterate over left or right half
        // // depending on the condition
        if(ar[mid]<=x){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }

    // if index not found
    if(!flag) return -1;
}
/**
 * Count number of occurences of x in ar
 * @param {array} ar input array
 * @param {int} n size of ar
 * @param {int} x input number, whose occurences has to be find
 * @return {int} occurences of x in ar
 */
int countX(int x,int ar[],int n){
    int leftMostIdx = getLeftMostIdx(ar,x,n);
    int rightMostIdx = getRightMostIdx(ar,x,n);
    return rightMostIdx-leftMostIdx+1;
}
// driver code
int main(){
	// I/O
	IOS;

    #ifndef ONLINE_JUDGE 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);  
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
	// cout<<"Started\n";
    int n;
    cin>>n;
    int ar[n];
    for(int i=0; i<n; i++) cin>>ar[i];
    
    cout<<countX(3,ar,n);
	cout<<"\nDone:)\n";
	return 0;
}