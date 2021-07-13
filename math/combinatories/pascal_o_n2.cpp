//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description :
// T.C         : O(n^2)
// A.S         : O(n^2)
//============================================================================
#include<bits/stdc++.h>
using namespace std;
#define twoD(row,col,name) int **name=new int*[row];for(int i=0;i<row;i++){name[i]=new int[col];}
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

/**
 * Function to generate pascal traingle. 
 * every row i has i elements in pascal traingle. 
 * every element of any row is binomial coefficnt of row number 0 to row
 * @param n size of traingle
 * @param c matrix
 */
void pascal(int n,int **c){
	for(int line = 0; line < n; line++){
		for(int elemOfLine = 0; elemOfLine <= line; elemOfLine++){
            if(elemOfLine==0||line==elemOfLine)
                c[line][elemOfLine]=1;
            else c[line][elemOfLine]=c[line-1][elemOfLine-1]+c[line-1][elemOfLine];
            cout<<c[line][elemOfLine]<<" ";
		}
		cout<<endl;
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
    int n;
	cin>>n;
    twoD(n,n,c);
    pascal(n,c);
	return 0;
}