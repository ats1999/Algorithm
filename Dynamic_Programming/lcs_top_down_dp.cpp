//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description :
// T.C         : O(m*n)
// A.S         : O(m*n)
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

/**
 * Find the size of longest common subsequence between two strings.
 * @param {a} first string
 * @param {b} second string
 * @param  {n} size of a
 * @param {m} size of b
 * @param i index of a from where to start matching
 * @param j index of b from where to start matching
 * @return size of LCS. 
 */
int dp[4][10];
int lcs(string a,string b,int n,int m,int i,int j){
    // any of the string riches it's end
    if(i==n||j==m)
        return 0;

    // if current charcter of both string is same then this is part of LCS. 
    // we have to move forward
    if(a[i]==b[j]){
        if(dp[i][j]=-1)
            return dp[i][j];
        else {
            dp[i][j]=1+lcs(a,b,n,m,i+1,j+1);
            return dp[i][j];
        }
    }
        // if current charcter of both string is not same then this is not the part of LCS. 
    else{
        dp[i][j]=max(lcs(a,b,n,m,i+1,j),lcs(a,b,n,m,i,j+1));
        return dp[i][j];
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
    memset(dp,-1,sizeof dp);
    // abcdefghij    ecdgi
    string a="",b="";
    cin>>a>>b;
    int dp[a.length()][b.length()];
    memset(dp,-1,sizeof dp);
    cout<<lcs(a,b,a.length(),b.length(),0,0)<<endl;

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
	return 0;
}