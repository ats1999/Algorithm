//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
//=============================================================================
// Description : Given an array of length n and an integer k (n>k), you have to 
//               find the sum of xor of all the elements of the sub-arrays which are of length k.
//=============================================================================
// T.C         : O()
// A.S         : O()
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

/**
 * This is naive approach to find array xor sum. 
 * @param ar input array
 * @param n size of ar
 * @param k size of subarray.
 */
int sumXorNaive(int ar[],int n,int k){
    // if length of the array is less than k
    if(n<k)
        return 0;

    int sum=0;
    int xOr;
    // traverse all subarray of size k
    for(int i=0;i<n-k+1;i++){
        xOr=ar[i]; // initial value
        for(int j=i+1;j<i+k;j++){
            // xor of subarray 
            xOr^=ar[j];
        }
        // include this subarray in sum
        sum+=xOr;
    }
    return sum;
}
/**
 * This is efficient approach to find array xor sum. 
 * @param ar input array
 * @param n size of ar
 * @param k size of subarray.
 */
int sumXorEfficent(int ar[],int n,int k){
    // if length of the array is less than k
    if(n<k)
        return 0;
    
    // array that store xor of all elements from 0 to i
    int x[n];
    int result=0;

    for(int i=0;i<n;i++){
        // if i is greater than zero then store xor of all elements from 0 to i 
        // in x[i]
        if(i>0)
            x[i]=x[i-1]^ar[i];
        else
            x[i]=ar[i];

        // if subarray of length k ends at i
        if(i>=k-1){
            int sum=x[i];

            // now find subarray of length k who ends at i
            // xor sum with x[i-k]
            if(i-k>-1)
            sum^=x[i-k];

            // Add the xor of elements from i-k+1 to i 
            result += sum; 
        }
        
    }
    return result;
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
    
    /*
    naive approach is to traverse all the array of length k and find the xor of all 
    elements in the subarray and sum them up.
    T.C is O(n^2)
    */ 

   /*
   Efficient Solution: The efficient solution is to traverse the array and find all
    the subarray of length k, i.e. ( 0 to k-1), (1 to k), (2 to k+1), …., (n-k+1 to n).
   */
    int n,k;
    cin>>n>>k;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    cout<<"Sum using naive approach: ";
    cout<<sumXorNaive(ar,n,k)<<endl;
    cout<<"Sum using efficient approach: ";
    cout<<sumXorEfficent(ar,n,k)<<endl;
	return 0;
}