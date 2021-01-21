//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : https://www.codechef.com/JAN21C/problems/WIPL
// T.C         : O()
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
int H[4001],N,K;
long long SUM;
// driver code
int main(){
	// I/O
	IOS;

    #ifndef ONLINE_JUDGE 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);  
	    //freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
	int t;
    cin>>t;
    while(t--){
        SUM=0;
        cin>>N>>K;
        for(int i=0; i<N; i++) {
            cin>>H[i];
            SUM+=H[i];
        }
        
        if(SUM<(2*K)){// not possible
            cout<<(-1)<<endl; continue;
        }
        
        sort(H,H+N);
        long long curSum =0,tempSum=0, count=0,curCount=0;
        int i=0, j=N-1;
        while(j>=0 && ((H[j]+curSum)<=K || curSum==0)){
            curSum+=H[j]; j--; count++;
        }
        
        while(i<j&&(curSum<K)){
            tempSum+=H[i];
            if((curSum+tempSum)>=K){
                if(tempSum<H[j]){
                    curSum+=tempSum;
                    count+=curCount+1;i++;
                    break;
                }else{
                    curSum+=H[j]; j--; i=0; 
                    count++;
                    break;
                }
            }
            curCount++;
            i++;
        }
        curSum=0;
        bool flag = true;
        while(j>=i){
            curSum+=H[j]; count++;
            if(curSum>=K){
                flag=false;
                cout<<count<<endl; break;
            }
            
            j--;
        }
        if(flag) cout<<(-1)<<endl;
    }
	return 0;
}