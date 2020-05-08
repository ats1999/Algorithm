//============================================================================
// Name        : saive_prime.h
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14 
// Copyright   : Everyone can freely use and distribute it.
// Description : Implement saive of Eratosthenes algorithm to count/find prime number in the given range. 
// T.C         : O(n(log(logn)))
// A.S         : O(n)
//============================================================================

void saive(int *ar,int n){
	// mark all  number as prime number initially
	for(int i=3;i<n;i+=2)
		ar[i]=1;
	
	// sieve
	for(int i=3;i<n;i+=2){
		// if the current number is not markes ( it is prime. )
		if(ar[i]==1){
			// mark all multiple of i as not prime
			for(int j=i*i;j<n;j+=i){
				ar[j]=0;
			}
		}
	}
	// special case
	ar[2]=1;
	ar[1]=ar[0]=0;
}
