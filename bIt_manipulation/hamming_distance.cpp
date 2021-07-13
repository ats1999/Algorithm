//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Implemention of hamming distance problem using bit optimization. 
//             : Given two string and the problem is to count number of positions where they differ.
// T.C         : O()
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

/**
 * Calculates hamming distance b/w two strings. 
 * 10000 random bit string of length 30 tooks 13.5 sec..
 * @param {string} a 
 * @param {string} b 
 * @return {int} hamming distance of a and b.
 */
int hammingDistance(string a,string b){
    int len;

    len=a.length();

    int d=0;
    for(int i=0;i<len;i++){
        if(a[i]!=b[i])
            d++;
    }
    return d;
}

/**
 * Calculates hamming distance b/w two integers of 0's and 1's. 
 * Size must be less than 31 or system dependent. 
 * 10000 random bit string of length 30 tooks 0.5 sec..
 * @param {int} a 
 * @param {int} b 
 * @return {int} hamming distance of a and b.
 */
int hammingDistanceBit(int a,int b){
    return __builtin_popcount(a^b);
}
// driver code
int main(){
	cout<<"Started\n";
	// I/O
	IOS;

    #ifndef ONLINE_JUDGE 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);  
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
    
	return 0;
}