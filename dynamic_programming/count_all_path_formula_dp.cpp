//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Count all paths from top left corner to the bottom right corner...
// T.C         : O(row-1).
// A.S         : O(1) to store DP table

// https://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/
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
     // We have to calculate m+n-2 C n-1 here 
    // which will be (m+n-2)! / (n-1)! (m-1)! 
    int path = 1; 
    for (int i = row; i < (col + row - 1); i++) { 
        path *= i; 
        path /= (i - row + 1); 
    } 
    return path; 
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
    cout<<countAllPath(4,4);
	return 0;
}