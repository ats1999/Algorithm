//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Find all prime factors of the given number. 
//               https://cp-algorithms.com/algebra/factorization.html
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

// Hack1
/**
 * This function finds and print all the prime factor of the given number. 
 * 
 * If a number is not divisible by 2 then it is redunded to check any further even number. 
 * This will reduce the time by 50%.
 * 
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
             i+=2;
        if(i>n)
         break;
    }
    return factors;
}


// Hack 2
/**
 * This function finds and print all the prime factor of the given number. 
 * 
 * "If a number is not divisible by 2 then it is redunded to check any further even number" 
 * We can extend this concept to 3 and 5. So if a number is not divisible by 2,3,5 then we
 * do not need to check further multiplier of this number. 
 * 
 * This will leave us with only 33%.
 * 
 * @param n input number. 
 */
vector<int> factorOfn(long long int n){
    //vector<int>factors(sqrt(n));
    vector<int>factors;
    // while n is divisible by 2,3,5
    // after that n must be not divisible by  2,3,5
    int sq=sqrt(n);
    for(int d:{2,3,5}){
        while(n%d==0){
            n/=d;
            factors.push_back(d);
        }
    }
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (long long d = 7; d * d <= n; d += increments[i++]) {
        while (n % d == 0) {
            factors.push_back(d);
            n /= d;
        }
        if (i == 8)
            i = 0;
    }
    if (n > 1)
        factors.push_back(n);
    return factors;
}
// check more hacks
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