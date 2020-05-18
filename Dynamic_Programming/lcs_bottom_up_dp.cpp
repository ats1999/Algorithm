
//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description :
// T.C         : O()
// A.S         : O()
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

int lcs(string a,string b,int n,int m,int i,int j){
    // any of the string riches it's end
    if(i==n||j==m)
        return 0;
    int lcs[n+1][m+1];
    for(int row=0;row<=n;row++)
        lcs[row][0]=0;
    for(int col=0;col<=m;col++)
        lcs[0][col]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1])
                lcs[i][j]=1+lcs[i-1][j-1];
            else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
        }
    }
    return lcs[n][m];
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
    
    // abcdefghij    ecdgi
    string a="",b="";
    cin>>a>>b;
    cout<<a.length()<<" "<<b.length()<<endl;
    cout<<lcs(a,b,a.length(),b.length(),0,0)<<endl;
	return 0;
}