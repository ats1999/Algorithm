//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : number pf ways we can make change of a cents. 
// T.C         : O(n*m)
// A.S         : O(n*m)
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
int DP[300][300]; // DP table. 
/**
 * This function retrun the number of  ways we can make change of any given amount.
 * @param coins denomination array
 * @param number to make change
 * @param n number of denominations. 
 */
int numberOfWays(int coins[],int number,int n){
    int DP[n+1][number+1];

    // If i have no coin then i can not make change of any number except zero
    for(int i=0;i<=number;i++)
        DP[0][i]=0;
    // I don't have money to make change, but i have coin
    for(int i=0;i<=n;i++)
        DP[i][0]=1;

    // count the way we can make change using current coin + not including current coin
    for(int row=1;row<=n;row++){
        for(int col=1;col<=number;col++){
                if(col-row<0){
                    DP[row][col]=DP[row-1][col];
                }else{
                    DP[row][col]=DP[row][col-row]+DP[row-1][col];
                }
        }
    }
    return DP[n][number];
}
// driver code
int main(){
    IOS;
    memset(DP,-1,sizeof DP);
    int n,m; cin>>n>>m;
    int coin[m];
    for(int i=0;i<m;i++){
        cin>>coin[i];
    }
    cout<<numberOfWays(coin,m,n);
    return 0;
}