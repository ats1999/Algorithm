//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Count the miminum number of coins needed to make the change.
// T.C         : O(n)
// A.S         : O(n)
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
/**
* This function find the minimum number of coins needed to make change of the given number.
* @param coin:  Contains coins with their value
* @param n : an int - number required to make change.
* @return best: minimum number of coins
*/
int makeChange(int n,vector<int>coins){
    int ar[n+1];
    ar[0]=0;
    for(int i=1;i<=n;i++){
        ar[i]=INT_MAX-10000;
        for(int c:coins){
            if(i-c>0){
                ar[i]=min(ar[i],ar[i-c]+1);
            }
        }
    }
    return ar[n];
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
    vector<int>coins{1,3,4};
    int n;
    cin>>n;
	
    cout<<makeChange(n,coins);
	return 0;
}
