//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Find all prime factors of the given number. 
// T.C         : O(n)
// A.S         : O()
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
/**
 * This function finds and print all the prime factor of the given number. 
 * @param n input number. 
 */
vector<int> factorOfn(long long int n){
    //vector<int>factors(sqrt(n));
    vector<int>factors;
    // while n is divisible by 2 
    // divide n by 2 and print 2
    // after that n must be odd 
    int sq=sqrt(n);
    while(n%2==0){
        n/=2;
        factors.push_back(2);
    }
    int i=3;
    while(n>0){
        if(n%i==0){
            n/=i;
            factors.push_back(i);
        }else
             i++;
        if(i>n)
         break;
    }
    return factors;
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
    int n;

    cin>>n;
    vector<int>fact=factorOfn(n);
    for(int i:fact)
        cout<<i<<" ";
	return 0;
}