//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Find the number of ways we can repersent the integer n. 
// T.C         : O(N) - using DP, otherwise O(2^N)
// A.S         : O(N)  - using DP, otherwise O(1)
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

/**
 * This function finds the number of ways we can repersent the given integer. 
 * Time complexity :- O(2^n)
 * 
 * Take a example where n = 2. 
 * In this case answer is 2.
 * Solution, 1> 1 + 1, 2> 2.
 * 
 * @param {int} n
 * @return {int} number of ways we can repersent n.
 */
int numWays(int n){
    // n==0 repersent, we found a soltion
    if(n==0)
        return 1;

    // this variable holdes the number of ways we can repersent n
    int soln = 0;

    // for each i <= N, include it in the solution once and check if it is right
    for(int i = 1; i <= n; i++)
        soln += numWays(n-i);

    return soln;
}

/**
 * This function finds the number of ways we can repersent the given integer. 
 * Time complexity :- O(n)
 * 
 * Take a example where n = 2. 
 * In this case answer is 2.
 * Solution, 1> 1 + 1, 2> 2.
 * 
 * @param {int} n
 * @return {int} number of ways we can repersent n.
 */
int DP[1000];

int numWaysDP(int n){
    // n==0 repersent, we found a soltion
    if(n==0){
        return 1;
    }

    // if it's value is already calculated
    if(DP[n])
        return DP[n];

    // this variable holdes the number of ways we can repersent n
    int soln = 0;

    // for each i <= N, include it in the solution once and check if it is right
    for(int i = 1; i <= n; i++)
        // if it's value is not already calculated
            soln += numWays(n-i);

    DP[n] = soln;
    return soln;
}
/**
 * This function finds the number of ways we can repersent the given integer. 
 * Time complexity :- O(1)
 * 
 * Take a example where n = 2. 
 * In this case answer is 2.
 * Solution, 1> 1 + 1, 2> 2.
 * 
 * fact is that there are n-1 possible positions for +-signs in the
 * sum and we can choose any subset of them.
 * 
 * @param {int} n
 * @return {int} number of ways we can repersent n.
 */
int numWaysFormula(int n){
    return pow(2,n-1);
}
// driver code
int main(){
	cout<<"Started\n";
	// I/O
	IOS;

    #ifndef ONLINE_JUDGE 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);  
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
    int n;
    cin>>n;
    memset(DP,0,sizeof DP);
    cout<<numWaysFormula(n);
	cout<<"\nDone:)\n";
	return 0;
}