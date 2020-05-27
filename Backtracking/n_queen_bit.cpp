//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Implement N-Queen problem, with backtracking. 
//  Print all possible placements using bit optimization. 
// T.C         : O()
// A.S         : O()
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)


// make a bitset for bit masking. 
bitset<30>col,d1,d2;
int totelNumberOfWays=0;
/**
 * Check is n queens can be placed int how many ways on NxN chess board. 
 * @param r  row
 * @param n number of queens
 */
void solveNQueen(int r,int n){
    if(r==n){
        totelNumberOfWays++;
        return;
    }
    // the idea behiend bitmasking is 
    // 1. Make an array of column and if there is any queen placed on this column, then make set this bit
    //      Next time we can check in O(1) time insted of O(n) time. 
    // 2. Difference of each diagonal cell of row and column having equal value. 
    //     Create bitset for array make those diagonal bit set on which any queen is placed. 
    for(int c=0;c<n;c++){
        if(!col[c] && !d1[r-c+n-1] && !d2[r+c]){
            col[c] = d1[r-c+n-1] = d2[r+c]=1;
            solveNQueen(r+1,n);
            col[c] = d1[r-c+n-1] = d2[r+c]=0;
        }
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
    int n; // number queens
    cin>>n;
    solveNQueen(0,n);

    cout<<totelNumberOfWays;
	return 0;
}