//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Print all possible path from top left corner to bottom right corner. 
// T.C         : O()
// A.S         : O(1)
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
// read and print array of integers
#define deb(x,s) cout<<"#"<<s<<": "<<x<<"\n";
#define dar(ar,n) for(int i=0;i<n;i++) {cout<<"#."<<i<<ar[i]<<",";cout<<endl;}
#define d2d(ar,n) for(int i=0;i<n;i++) {for(int j=0;j<n;j++){cout<<ar[i][j]<<" ";}cout<<endl; }
#define rd_ar_int(name,size) int name[size]; for(int i=0;i<size;i++){ sd(name[i]);}
#define print_ar(name,size,dele) for(int i=0;i<size;i++){ cout<<name[i]<<dele; }
// 2D array
#define twoD(row,col,name) int **name=new int*[row];for(int i=0;i<row;i++){name[i]=new int[col];}
// maze matrix

/**
 * This function prints all possible path from top left corner to bottom right corner.
 * @param row {row of matrix }
 * @param col {column of matrix}
 */
void printPath(int row,int col,int **maze,int N){
    // mark this cell as visited
    maze[row][col]=1;
    // BASE CASE
    // if path found then print
    if(row == N-1 && col == N-1){
        cout<<"\nPrinting\n";
        cout<<"\n\n";
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(maze[i][j]==1)
                    cout<<"1";
                else cout<<"0";
            }
            cout<<endl;
        }
        cout<<"\n\n";
        return;
    }
    // d2d(maze,N);
    // deb(row,"row");deb(col,"col");deb(N,"N");
    
    //BACK_TRACK
    // if there is a way to go right then move right
    if(col<N-1)
        printPath(row,col+1,maze,N);


    // if there is a way to move bottom then move bottom
    if(row<N-1)
        printPath(row+1,col,maze,N);

    // // if there is a way to move left then move left
    // if(col>0)
    //     {
    //     	printPath(row,col-1,maze,N);
    //     	cout<<"\nleft\n";
	// 	}

    //  // if there is a way to move top then move top

    // if thah path not already visited. 
    // if(row>0)
    //     printPath(row-1,col,maze,N);
    // // if there is a way to move upper-left-diagonal then move  upper-left-diagonal
    // if(row>0&&col>0)
    //     printPath(row-1,col-1,maze,N);
    // // if there is a way to move  upper-right-diagonal then move upper-right-diagonal
    // if(row>0&&col<N)
    //     printPath(row-1,col+1,maze,N);
    // // if there is a way to move bottom-left-diagonal then move bottom-left-diagonal
    // if(row>N&&col>0)
    //     printPath(row+1,col-1,maze,N);
    // if there is a way to move bottom-right-diagonal then move bottom-right-diagonal
    if(row<N-1&&col<N-1)
        printPath(row+1,col+1,maze,N);
    
    maze[row][col]=0;
    return;
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
    int n;
    cin>>n;
    int **maze=new int*[n];
    for(int i=0;i<4;i++){
    	maze[i]=new int[n];
	}
    for(int i=0;i<n;i++){
        for(int  j=0;j<n;j++){
            maze[i][j]=0;
        }
    }
    cout<<"Printed\n";
    printPath(0,0,maze,n);
    cout<<"Printed\n";
	return 0;
}
