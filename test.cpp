//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Implemention of sigmented seive
// T.C         : O()
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define sn(n) int n;scanf("%d",&n)
#define pf(n) cout<<n<<" "
#define pfn(n) cout<<n<<endl
#define inar(ar,n) int ar[n]; for(int i=0;i<n;i++) cin>>ar[i]
#define pfar(ar,n) for(int i=0;i<n;i++) cout<<ar[i]<<" "; cout<<endl
#define pfarn(ar,n) for(int i=0;i<n;i++) cout<<ar[i]<<"\n"
#define line cout<<endl;
// driver code
int main(){
	cout<<"Started\n";
	#ifndef ONLINE_JUDGE 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);  
    #endif 
	sn(n);
	deque<int>dq;
	for(int i=0; i<n;i++){
		sn(t);
		dq.push_back(t);
	}
	dq.pop_back();
	for(deque<int>::iterator it=dq.begin();it!=dq.end(); it++){
		pf(*it);
	}
	cout<<"\nDone:)\n";
	return 0;
}
