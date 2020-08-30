//============================================================================
// Name        : egcd.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Implemention of extended acludion algorithm.
// T.C         : O()
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

/**
 * @param {a} 
 * @param {b}
 * @param {&x} - this is required to compute coefficient of a and b 
 * @param {&y} - this is required to compute coefficient of a and b
 * @return {gcd} - gcd of a and b
 */
int eGcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int g = eGcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1*(a/b);
    return g;
}
// driver code
int main(){
	// I/O
	IOS;

    #ifndef ONLINE_JUDGE 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);  
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
	cout<<"Started\n";
    int a, b, x, y;
    cin>>a>>b;
    cout<<"Gcd of a and b is :"<<eGcd(a,b,x,y)<<endl;
    cout<<"Value of x and y is: "<<x<<", "<<y<<endl;
	cout<<"\nDone:)\n";
	return 0;
}