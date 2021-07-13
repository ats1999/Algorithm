//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Number of ways we can make change. 
// T.C         : O(n*m)
// A.S         : O()
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
 * @param i current coin for which we have to take decision, either include or not. 
 */
int numberOfWays(int coins[],int number,int i){
    // if there is no coin then 
    if(i<0)
        return 0;
    // if i have no money
    if(number<0)
        return 0;
    if(DP[i][number]!=-1)
        return DP[i][number];
    //  if i got the change
    if(number==0){
        DP[i][number]=1;
        return 1;
    }
    
    // recur
    // one time select the current coin
    // do not select the current coin
    DP[i][number]= numberOfWays(coins,number-coins[i],i)+numberOfWays(coins,number,i-1);
    return DP[i][number];
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
    cout<<numberOfWays(coin,n,m);
    return 0;
}