//============================================================================
// Name        : prime_in_range.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description :
// T.C         : O()
// A.S         : O()
//============================================================================
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono; 
#include "saive_prime.h"
#include "is_prime_in_range_6k.h"


// driver code
int main(){
	// fast I/O
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<"start\n";
    // saive
     // Get starting timepoint 
    auto start = high_resolution_clock::now(); 
    int n=10000;
    int ar[n]={0};
    saive(ar,n); // call saive
    int count=0;
    for(int i=0;i<n;i++)
    	if(ar[i]==1){
    		count++;
    		//cout<<i<<" ";
		}
	cout<<"Total: "<<count<<endl;
	// Get ending timepoint 
    auto stop = high_resolution_clock::now(); 
    // Get duration. Substart timepoints to  
    // get durarion. To cast it to proper unit 
    // use duration cast method 
    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "\n Time taken by function: "
         << duration.count() << " microseconds" << endl;
	//cout<<"Total: "<<primeCount(500)<<endl;
	return 0;
}




/**

Saive

......
N		T		S
2000 	3999		15 kb

			



*/
