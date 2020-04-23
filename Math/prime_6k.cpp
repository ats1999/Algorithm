//============================================================================
// Name        : prime_6k.cpp
// Author      : Rahul
// Version     : 2.0
// Copyright   : Everyone freely can use and distribute it.
// Description : Count prime number less or equals to a value n.
//============================================================================

// use the concept that every primt number is of form 6k+1 or 6k-1 except 2 and 3.
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
 * Complete the primeCount function below.
 */
int primeCount(unsigned long long int n) {
    // case n=1
    if(n<=1)
        return 0;
    // case n=2,3,4,5,6
     if(n<=5)
        return 1;
    // case n=7,8,...,30 ------------ 2*3*5=30
        if(n<30)
            return 2;
    // more than 6
    unsigned long long int k=1,nextOne=0,nextTwo=0,test=6,ans=2;
    while(1){
        nextOne=(6*k)-1;
        nextTwo=(6*k)+1;
        if(isPrime(nextOne)){
            if(test*nextOne<=n){
                test*=nextOne;
                ans++;
            }else return ans;
        }
        if(isPrime(nextTwo)){
            if(test*nextTwo<=n){
                test=test*nextTwo;
                ans++;
            }else return ans;
        }
        k++;
    }
    return ans;
    
}
