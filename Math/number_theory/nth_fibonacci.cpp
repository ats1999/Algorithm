//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : make an iterative solution...
// T.C         : O()
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
/**
 * This function calculates nth fibonacci.
 * @param {n} - input number 
 * @return {pair<int,int>} - fn and fn-1 fibonacci
 */
pair<int,int> nthFibonacci(int n){
    if (n == 0)
        return {0, 1};
		
    auto p = nthFibonacci(n >> 1);
    int c = p.first * (2 * p.second - p.first);
    int d = p.first * p.first + p.second * p.second;

	cout<<n<<" th fib--> ";
    if (n & 1){
		cout<<d<<" n&1 "<<c+d<<endl;
		return {d, c + d};
	}   
    else{
		cout<<c<<" "<<d<<endl;
        return {c, d};
	}
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
    int n;
    cin>>n;
    cout<<nthFibonacci(n).first<<" , "<<nthFibonacci(n).second;
	cout<<"\nDone:)\n";
	return 0;
}