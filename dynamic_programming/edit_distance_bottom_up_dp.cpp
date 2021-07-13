//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Implement edit distance problem in a bottom up  manner. 
// T.C         : O(n*m)
// A.S         : O(n*m)
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

int DP[50][50];

/**
 * This function count edit diistance between string x and y.
 * @param x a string
 * @param y another string
 * @param m size of x
 * @param n size of y
 * @return distance
 */
int editDistance(string x,int m,string y,int n){
    for(int i=0;i<=m;i++)
        DP[i][0]=i;
    for(int i=0;i<=n;i++)
        DP[0][i]=i;
    
    int  substitutionCost=0;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1]!=y[j-1])
                substitutionCost=1;
            
            DP[i][j]=min(DP[i-1][j]+1,min(DP[i][j-1]+1,DP[i-1][j-1]+substitutionCost));
        }
    }
    return DP[m][n];
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
    memset(DP,0,sizeof DP);
    
    string x,y;
	cin>>x>>y;
	int m,n;
	m=x.length(),n=y.length();
	cout<<editDistance(x,m,y,n);
	return 0;
}