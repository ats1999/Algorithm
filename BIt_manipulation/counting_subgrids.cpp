//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : This is standered bit optimization problem. 
// T.C         : O()
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

// size of grid
int const N=5;

// grid whose each square is either 1 or 0. 
int grid[N][N]={
    {0,1,0,0,1},
    {0,1,1,0,0},
    {1,0,0,0,0},
    {0,1,1,0,1},
    {0,0,0,0,0}
};

/**
 * Count number of subgrids with all corners as 1 without using bit manupulation. 
 * @return {int} number of subgrids whose all corners is 1.
 */
int  countGrid(){
    int count=0;
    for(int a=0;a<N;a++){
        for(int b=0;b<N;b++){
            for(int i=0;i<N;i++){
                if(grid[a][i] == 1 && grid[b][i] == 1)
                    count++;
            }
        }
    }
    return count*(count-1)/2;
}

/**
 * Count number of subgrids with all corners as 1 using bit manupulation.
 * @return {int} number of subgrids whose all corners is 1.
 */
int  countGridBit(){
    
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
    cout<<countGrid();
	return 0;
}