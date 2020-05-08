//============================================================================
// Name        : is_prime_in_range_6k.h
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Heaer of prime function. 
// T.C         : O(n^1/2)
// A.S         : O(1)
//============================================================================


// use the concept that every primt number is of form 6k+1 or 6k-1 except 2 and 3.
/**
* Funstion to check wheather a number is prime or not. 
* @param n: number to check
* @return true if number is prime, false otherwise.
*/
bool isPrime(unsigned long long int n) 
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
 
/*
 * Count primt number in a given range. 
 * Use 6k-1 and 6k+1 technique. 
 * @param n : given range
 * @return count of primes numbers in the given range. 
 */
int primeCount(unsigned long long int n) {
    // case n=1
    if(n<=1)
        return 0;
    // case n=2,3,4,5,6
     if(n<=5)
        return 2;
    
    // print 2 & 3
    cout<<2<<" "<<3<<" ";
    // more than 6
    unsigned long long int k=1,nextOne=0,nextTwo=0,ans=2;
    while(1){
        nextOne=(6*k)-1;
        nextTwo=(6*k)+1;
        
        if(nextOne>n||nextTwo>n)
        	return ans;
        if(isPrime(nextOne)&&nextOne<=n){
        	cout<<nextOne<<" ";
        	ans++;
        }
        
        if(isPrime(nextTwo)&&nextTwo<=n){
        		cout<<nextTwo<<" ";
            	ans++;
        }

        k++;
    }
    return ans;
}
