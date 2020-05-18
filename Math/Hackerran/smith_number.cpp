//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : According to statement, a number is smith number if sum of its digits is 
//               equal to the sum of digits of it's prime factors. 
// Link        : https://www.hackerrank.com/challenges/identify-smith-numbers/problem
// T.C         : O()
// A.S         : O()
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

 bool isPrime(long long int n) 
{ 
    // Corner cases 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    // This is checked so that we can skip  
    // middle five numbers in below loop 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
}
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
int sumOfDigit(long long int n){
	int sum=0;
	while(n>0){
		sum+=n%10;
		n/=10;
	}
	return sum;
}
int isSmith(long long int n){
    if(isPrime(n))
        return 0;
    int sumOfDigitOfn=sumOfDigit(n);

    //cout<<"Sum of digit: "<<sumOfDigitOfn<<endl;
    vector<int>factors;
    factors=factorOfn(n);
    int sumOfFactor=0;
    for(int digit:factors){
        sumOfFactor+=sumOfDigit(digit);
    }
    //cout<<"\nSum of factors: "<<sumOfFactor<<endl;
    if(sumOfDigitOfn==sumOfFactor)
        return 1;
    return 0;
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
    long long int n;
    cin>>n;
    cout<<isSmith(n);
	return 0;
}