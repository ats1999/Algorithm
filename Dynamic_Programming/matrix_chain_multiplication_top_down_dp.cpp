//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description :
// T.C         : O(n^3)
// A.S         : O()
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

int tdp[4][4]; // top down dp array
/**
 * This function finds best order of matrices to be multiplied.
 * @param {m} array containing row and colums of matrices
 * @param {i} start index
 * @param {i} end index
 * @return order of matrix || cost of multiplication 
 */
int matrixChain(int m[],int i,int j){
    //if there is single matrix to multipy then cost will be zero
    if(i==j){
        tdp[i][j]=0;
        return 0;
    }
    
    if(tdp[i][j]!=-1){
        return tdp[i][j];
    }else{
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            int temp=matrixChain(m,i,k)+matrixChain(m,k+1,j)+m[i-1]*m[k]*m[j];
            tdp[i][j]=ans=min(ans,temp);
        }
        return ans;
    }
}
// driver code
int main(){
	cout<<"Started\n";
	// I/O
	//IOS;
    
    #ifndef ONLINE_JUDGE 
	    // For getting input from input.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin); 
	    // Printing the Output to output.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
    // set all value of tdp to -1
    memset(tdp,-1,sizeof tdp);
    int m[]={1,2,3,4};
    cout<<matrixChain(m,1,3)<<endl;

    for(int i=1;i<5;i++){
        for(int j=1;j<5;j++){
            cout<<tdp[i][j]<<" ";
        }
        cout<<endl;
    }
	return 0;
}