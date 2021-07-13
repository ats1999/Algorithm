//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Prints nCr table for given number. 
// T.C         : O()
// A.S         : O()
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

/**
 *This function prints nCr table for given number. 
 *@param n input number. 
 */
/**
 * nCr table is to print nth row of pascall traingle. 
 * @param n number --- print nC0, nC1,..,nCn
 */
void ncrTable(int n){
    int k=n;
    long long int c[k+1];
    memset(c,0,sizeof c);
    c[0]=1;
	for(int i=1;i<=n;i++){
        for(int j=min(i,k);j>0;j--){
            c[j]=c[j]+c[j-1]%1000000000;
        }
    }
    for(int i:c)
        cout<<i<<" ";
        cout<<endl;
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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ncrTable(n);
    }
	return 0;
}