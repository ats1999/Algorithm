//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Count all paths from top left corner to the bottom right corner...
// T.C         : O(2^n) if only move is right or bottom...
//			   : O(3^n) if only move is right or bottom or lower right corner... and same for other...
// A.S         : O(n*n) to store DP table
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
int grid[100][100];

int countAllPath(int row,int col){
    // every grid[i][0] has exeactly one path to vist from grid[0][0]
    for(int i=0;i<row;i++)
        grid[i][0]=1;

    // every grid[0][i] has exeactly one path to vist from grid[0][0]
    for(int i=0;i<col;i++)
        grid[0][i]=1;

    // grid[0][0] has zero path to visit from grid[0][0]
    grid[0][0]=1;

    // Dynamic programming
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            grid[i][j]=grid[i-1][j]+grid[i][j-1];
        }
    }

	return grid[row-1][col-1];
	
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
    memset(grid,-1,sizeof grid);
    cout<<countAllPath(3,3);
	return 0;
}