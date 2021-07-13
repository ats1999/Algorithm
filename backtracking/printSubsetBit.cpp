//============================================================================
// Name        : .cpp
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
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

int t;

/**
 * Print all subset of the given array set
 * @param {array} ar input array
 * @param {int} size array size
 */
void printSubset(int ar[], int size){
    int sizePowerSet = pow(2,size);
    for(int counter = 0; counter<sizePowerSet; counter++){
        for(int j=0; j<size; j++){
            if(counter & (1 << j))
                cout<<ar[j]<<" ";
        }
        cout<<endl;
    }
}
// driver code
int main(){
	// I/O
	IOS;

    #ifndef ONLINE_JUDGE 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);  
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
	cin>>t;
	while(t--){
		int n; cin>>n;
		int ar[n];
		for(int i=0; i<n; i++)
			cin>>ar[i];
			
        printSubset(ar,n);
	}
	return 0;
}