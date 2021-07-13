//============================================================================
// Name        : isPrime.cpp
// Author      : Rahul
// Version     : 2.0
// Copyright   : Everyone freely can use and distribute it.
// Description : To check weather a number is prime or not
// T.C 		   - O(n^1/2)
//============================================================================
 /*
 * This function check the given number that it is prime or not.
 * 
 * This function is basic primility test without any optimization.
 * 
 * @param integer number
 * @return boolean value indecating
 */
bool isPrime1(unsigned long long int n){
    for(int i=2;i<n;i++)
        if(n%i==0)
            return false;
    
    return true;
}

 /*
 * This function check the given number that it is prime or not.
 * 
 * If a number n/a=b then a|b<=n
 * 
 * @param integer number
 * @return boolean value indecating
 */
bool isPrime2(unsigned long long int n){
    for(int i=2;i<n/2;i++)
        if(n%i==0)
            return false;
    
    return true;
}


 /*
 * This function check the given number that it is prime or not.
 * 
 * if n/a=b the a|b <= sqrt(n)
 * Chech:- n=25,a=5,b=6 then a*b =30 which is greater than 25
 * @param integer number
 * @return boolean value indecating
 */
 bool isPrime(unsigned long long int n) 
{ 
    // Corner cases 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    // This is checked so that we can skip  
    // middle five numbers in below loop 
    if (n%2 == 0 || n%3 == 0) return false; 
    long long int sqr = sqrt(n);
    for (int i=5; i<=sqr; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
}
