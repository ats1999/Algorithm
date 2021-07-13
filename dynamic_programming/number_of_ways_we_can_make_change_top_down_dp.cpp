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
int DP[100][100]; // DP table. 
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
	cout<<"Started\n";
	// I/O
	IOS;
    #ifndef ONLINE_JUDGE 
	    // For getting input from input.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin); 
	    // Printing the Output to output.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
    memset(DP,-1,sizeof DP);
     int coin[]={2,5,3,6};
    int n;
    cin>>n;
    cout<<numberOfWays(coin,n,4);
	return 0;
}