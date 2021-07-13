//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Some useful bit operation...
// T.C         : O()
// A.S         : O()
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
/** 
 * This function prints bit reperesention of the given number. 
 * @param x input number
 */
void printBit(int x){
    for(int i=31;i>=0;i--){
        if(x&(1<<i))
            cout<<"1";
        else cout<<"0";
    }
    cout<<endl;
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
    int x=-5;
    unsigned int y=x;
    // cout<<"Unsigned value of "<<x<<" is: "<<y<<endl;
    // x=1,y=2;
    // int z=x&y;

    // // if x&1 is 0 if x is even, 1 otherwise
    // if(y&1){
    //     cout<<"y&1 \n";
    // }
    // cout<<"1&2="<<z<<endl;

    // // kth bit of x is one exactly when x&(1<<k) is not zero
    // // print bit  repersention of a number
    // x=5;
    // for(int i=31;i>=0;i--){
    //     if(x&(1<<i))
    //         cout<<"1";
    //     else cout<<"0";
    // }
    // cout<<endl;

    // set the kth bit of x..... k=2
    //x|(1<<1);
    printBit(x);
	return 0;
}