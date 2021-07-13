//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description :
// Link        : https://www.hackerrank.com/challenges/beautiful-pairs/problem
// T.C         : O()
// A.S         : O()
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

int beautifulPairs(vector<int> A, vector<int> B) {
    map<int, int> m1, m2;
    bool flag=false;
    int pairs=0;
    for (int i=0;i<A.size();i++)
        m1[A[i]]++;
    for (int i=0;i<B.size();i++)
        m2[B[i]]++;

    map<int, int>::iterator it = m1.begin();
    while(it!=m1.end())
    {
        pairs+=min(it->second, m2[it->first]);
        if (it->second!=m2[it->first])
            flag=true;
        it++;
    }
    if (flag)   return pairs+1;
    return pairs-1;
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
    int n;
    cin>>n;
    int a[n],b[n];

    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    
    // logic
     for(int i=0;i<n;i++)
        cout<<a[i];
    for(int i=0;i<n;i++)
        cout<<b[i];
	return 0;
}