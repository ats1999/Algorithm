//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Count all paths from top left corner to the bottom right corner...
// T.C         : O(2^n) if only move is right or bottom...
//			   : O(3^n) if only move is right or bottom or lower right corner... and same for other...
// A.S         : O(1)
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
/**
 * This function counts all path from top left corner to bottom right corner. 
 * @param row current row
 * @param col current col
 * @return number of path
 */
int countAllPath(int row,int col){
	// we reach firt to the row or col, there is only one path form begining. 
	if(row==1||col==1)
		return 1;
	 return countAllPath(row-1,col)+countAllPath(row,col-1);
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
    cout<<countAllPath(3,3);
	return 0;
}