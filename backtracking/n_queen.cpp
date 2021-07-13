//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Implement N-Queen problem, with backtracking.
// T.C         : O()
// A.S         : O()
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

/**
 * Check if the current queen can be placed or not in the current cell.
 * @param board chess bord
 * @param i starting column
 * @param j row
 * @param n number of queens
 * @return true if queen can be placed false otherwise. 
 */
bool isSafe(int board[][10],int i,int j,int n){
    // check for column
    for(int row=0;row<n;row++){
        if(board[row][j]==1){
            return false;
        }
    }

    // check for left diagonal
    int x=i,y=j;
    while(x>=0&&y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }

    // check for right diagonal
     x=i,y=j;
    while(x>=0&&y<n){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y++;
    }

    return true;
}

/**
 * Check is n queens can be placed or not on NxN chess board. 
 * @param board chess bord
 * @param i starting row
 * @param n number of queens
 * @return true if queens can be placed false otherwise. 
 */
bool solveNQueen(int board[][10],int i,int n){
    // base case
    if(i==n){
        // you have sucessfully placed n queens on row 0..n-1
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]){
                    cout<<" Q ";
                }else cout<<" _ ";
            }
            cout<<endl;
        }
        return true;
    }
    // recursive part
    for(int j=0;j<n;j++){
        // check i,j th position is safe to place the queen or not. 
        if(isSafe(board,i,j,n)){
            board[i][j]=1;
            bool nextQueen=solveNQueen(board,i+1,n);
            if(nextQueen)
                return true;

            board[i][j]=0;
        }
    }
    return false;
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
    int board[10][10]={0};
    if(!solveNQueen(board,0,n))
        cout<<"Queens can not be placed\n";
	return 0;
}