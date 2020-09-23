//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Implement sigment sieve algorithm.
// T.C         : O()
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(true);cin.tie(nullptr)
/**
 * This function calculates primes number from 1 to sqrt(n) and returns a vector.
 * @param {n} - input range
 * @return {vector<int>} - vector containing all primes from 1 to sqrt(n)
 */
vector<int> siveTillRoot(int n){
	int nsqrt = sqrt(n);

	// calcuates primes till root of n
	vector<int>primesTillRoot;
	vector<int>isPrime(sqrt(n)+1,true);

	for(int i=2; i<=nsqrt; i++){
		if(isPrime[i]){
			primesTillRoot.push_back(i);

			// if i is a primes number then mark all multiples of i as non prime number
			for(int j=i+i; j<=nsqrt; j+=i){
				isPrime[j] = false;
			}
		}
	}
	return primesTillRoot;
}
/**
 * This function calculates primes number from 1 to n and returns a vector.
 * @param {n} - input range
 * @return {vector<int>} - vector containing all primes from 1 to n
 */
vector<int> sigmentedSieve(int n){
	// caculates primes till root
	vector<int>primesTillRoot = siveTillRoot(n);
	vector<int>primes;
	
	int blockSize = sqrt(n); // your convenience
	bool primesInSigment[blockSize]; 
	memset(primesInSigment,true,sizeof primesInSigment);
	
		// iterate over block of size blockSize			
		for(int k=0; (k+1)*blockSize<=n; k++){
			cout<<"===========================++++++++++++++++++++=================\n";			
			cout<<"K: "<<k<<"\n";
			int startIdx = k*blockSize+1;
			int endIdx = (k+1)*blockSize;
			printf("StartIdx=%d, endIdx=%d\n",startIdx,endIdx);
			for(int i=startIdx;i<=endIdx;i++) cout<<i<<" "; cout<<endl;
			// mark all the composite number as composite in the  current  block
			for(int prime:primesTillRoot){
				startIdx = startIdx - (startIdx % prime);
				startIdx += prime;
				
				// starting number is prime then starting marking from next number 
				if(startIdx == prime)
					startIdx += startIdx;
				cout<<"Prime: "<<prime<<" ->No prime-> ";
				for(int i=startIdx; i<=endIdx; i+=prime){
					primesInSigment[i-startIdx] = false;
					cout<<(i-startIdx)<<" ";
				}cout<<endl;
			}
			for(int i=1;i<blockSize; i++){
				if(primesInSigment[i]){
					primes.push_back(i+k*blockSize);
					cout<<1<<" ";
				}else cout<<0<<" ";
			}cout<<endl;
			memset(primesInSigment,true,sizeof primesInSigment);
		}
	return primes;
}
// driver code
int main(){
	// I/O
	IOS;

    #ifndef ONLINE_JUDGE 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);  
    #endif 
	cout<<"Started\n";
	int n;
	cin>>n;
	
	vector<int>primes;
	primes=sigmentedSieve(n);
	 for(int i:primes)
	 	cout<<i<<endl;
	cout<<"\nDone:)\n";
	return 0;
}
