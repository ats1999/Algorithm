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

    int x1,y1;
    int g = eGcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1*(a/b);
    return g;
}

/**
 * Find value of x_val and y_val such that a*x_val + b*y_val = c
 * @param {a} - 
 * @param {b} - 
 * @param {c} - 
 * @param {&x_val} - 
 * @param {&y_val} - 
 * @return {bool} true if solution exists, false otherwise.
 */
bool diophantineEquation(int a, int b, int c, int &x_val, int &y_val){
    int xg, yg;
    int g = eGcd(a,b,xg,yg);
    if(c%g != 0)
        return false;
    
    x_val = xg*(c/g);
    y_val = yg*(c/g);
    return true;
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
    int a, b, c,x,y;
    cin>>a>>b>>c;

    if(diophantineEquation(a,b,c,x,y)){
        cout<<x<<", "<<y<<endl;
    }else
    {
        cout<<"No solution";
    }
    
	cout<<"\nDone:)\n";
	return 0;
}