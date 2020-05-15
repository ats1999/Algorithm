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
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
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
    // dimension of four matrices
    vector<pair<int,int>>matrices;
    matrices.push_back(make_pair(5,4));
    matrices.push_back(make_pair(4,6));
    matrices.push_back(make_pair(6,2));
    matrices.push_back(make_pair(2,7));

    vector<int>p; // algorithm helper data
    int last; // column of last matrix. 

    for(auto matrix:matrices){
        p.push_back(matrix.first);
        last=matrix.second;
    }    
    p.push_back(last);  // add last matrix. 
    int numberOfMatrix=matrices.size();

    int dp[numberOfMatrix][numberOfMatrix];
    for(int i=0;i<numberOfMatrix;i++){
        for(int j=0;j<numberOfMatrix;j++){
            dp[i][j]=0;
        }
    }

    // logic 

    //STEP 1:
    // if i==j then dp[i][j]=0
    // if j=i+1 then dp[i][j]=p[i-1]*p[i]*p[i+1]
    // else dp[i][j]=min(dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j]).... for i<=k<j

    for(int i=0;i<numberOfMatrix;i++){
        for(int j=0;j<numberOfMatrix;j++){
            if(i==j){
                dp[i][j]=0;
            }else if(j==i+1){
                dp[i][j]=p[i]*p[i+1]*p[i+2];
            }else{
                int best=INT64_MAX;
                for(int k=1;k<j;k++){
                    cout<<"DP: "<<dp[i][k]+dp[k+1][j]+p[i]*p[k+1]*p[j+1]<<endl;
                    dp[i][j]=min(best,dp[i][k]+dp[k+1][j]+p[i]*p[k+1]*p[j+1]);
                }
            }
        }
    }
    
    for(int i=0;i<numberOfMatrix;i++){
        for(int j=0;j<numberOfMatrix;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

	return 0;
}